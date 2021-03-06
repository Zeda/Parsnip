Parsnip is a parser for the TI-83+/84+. It is a work-in-progress, and there are features that are going to be changed
frequently. You are welcome to try this out, but your code might not work in a future version. For example, the
`Sprite()` command currently takes a `raw` type as its sprite. In the future, sprites will be their own type.

I basically took [Grammer 2](https://github.com/Zeda/Grammer2) and kept most of the the main menu code and some of the
other code, but totally rewrote the parser. It supports a variety of types, including 8-ish numeric types at the moment,
strings, and lists (not yet arrays). Speed-wise, it is on par with TI-BASIC, about 20% to 30% faster depending on what
you are doing.

Concepts are loosely inspired by my experience with other languages, especially C, Python, and TI-BASIC for the 68k
calcs like the TI-92/89/Voyager. 

![*Example with mixing types and variable storage*](https://i.imgur.com/2Nxgt7U.gif)
![*Example with user input and sprites*](https://i.imgur.com/G35t78t.gif)
![*Example with lists*](https://i.imgur.com/ttWTHxr.gif)


# Install

Using git:
```
git clone --recurse-submodules https://github.com/Zeda/Parsnip.git
```

Please note that this uses the z80float repository as a submodule, so you'll
need that `--recurse-submodules` option. In case you forgot that, then:

```
git submodule update --init --recursive
```


# Building
Once it is cloned, you'll need to compile the project.

This project uses [`spasm-ng`](https://github.com/alberthdev/spasm-ng) to
compile, and I use Linux. On Windows you can either use the [`Linux Subsytem`](https://www.windowscentral.com/install-windows-subsystem-linux-windows-10)(on Windows 10) and install spasm from there, or you can download the [`spasm-ng`](https://github.com/alberthdev/spasm-ng/releases) for Windows release.

Once installed you can:

## Linux
```
./compile
```

## Windows
```
spasm src\parsnip.z80 bin\parsnip.8xk -I z80float\single -I z80float\extended -I Z80-Optimized-Routines
```

# Examples
In lieu of a real readme, here are some examples that show how it works.


```
"HELLO"→Z
Disp Z
3.1415926535→X
355/113→Y
Disp X-Y
Fix 6
Disp X-Y
Disp Z+X
Pause
```

See [commands.md](commands.md) for a more complete set of commands documentation.

# How To Help
This project needs a **lot** of work, and not just in terms of planning.
It is going to need a frick-tonne of conversion routines to convert between
types. This is going to be one of the most tedious parts of the project!
If you'd like to help, you can add to the files in [src/convert](src/convert)
directory. You'll need to know:
* DE points to the start of the data
* All numeric values are stored in little-endian
* For the string type (`type_str`) and raw type, (`type_raw`)
(not `str_ref` or `tstr_ref`), BC is also the size of the string.

If you want to add a new function, you will need to add it to the
LUTs (Look Up Tables) in [src/commandtable.z80](src/commandtable.z80).
There is an `exec` table that is used when the token is parsed, and an `eval`
table for when a token is executed. Next, in
[src/parsnip.z80](src/parsnip.z80), find the `exec_disp` label, and add your
`exec_mytoken` label (replacing `mytoken` with the token name). Now, you can
add your `eval_mytoken` routine somewhere. Arguments are stored in reverse order
on the `operandstack`. If you are expecting a string argument, call
`popoperand_str` and HL will point to the string (or throw an error if it can't
convert to a string). If you want a uint8, `popoperand_ui8`. There are similar
routines, you'll need to read the comments for output:

* `popoperand_ui8` (uint8)
* `popoperand_ui16` (uint16)
* `popoperand_ui32` (uint32, not well supported)
* `popoperand_fixed88` (fixed-point 8.8, not well supported)
* `popoperand_fixed32` (fixed-point 16.16, not well supported)
* `popoperand_xfloat` (extended-precision float, fully supported)
* `popoperand_single` (single-precision float, all the float code is there, just
  no conversion routines yet)
* `popoperand_str` (string, this will attempt to convert)


And finally, ***you need to exit the routine with `jp pop_end_of_params`***.
If you are feeling really adventurous, this project needs a countargs routine
for functions that take a variable number of arguments.

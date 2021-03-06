# Overview
This is just a quick reference for what Parsnip supports. Some of this is likely
to change; this project is a work-in-progress. As well, I will likely not keep
this up-to-date as I am more focused on the parser. These commands are more to
test the parser and show off in screenshots what is possible.

# Types
Parsnip features a bunch of variable types, with plans for some more core types.
* `ui8`, `ui16`, `ui32` are the unsigned integers, where Parsnip
generally defaults to `ui16`. At this moment, signed integer types aren't
supported, but they are planned. (It's a bit tedious, and right now I'm focusing
on the parser itself).
* `true` and `false` are boolean types. When converted to a
string, they display `true` and `false`, respectively, but evaluate to `1` and
`0` for math. Ex., `3+(1=1)` returns `4` as you might expect in TI-BASIC.
* `xfloat` and `single` are float types, where Parsnip defaults to `xfloat`, a
higher-precision 80-bit float. Most of the math commands support `single` types,
but I don't think I have anything that outputs a `single` type to be used, yet.
* `fixed1616` and `fixed88` are somewhat supported. These are fixed-point formats,
and just as a proof-of-concept, integer division returns a `fixed1616` if it
doesn't divide evenly.
* `string` is a string type.
* `char` is a 1-byte character.
* `raw` is for raw data. Currently, this is what the sprite routine requires.
* `list` is a list of values that can be various types (even other lists).

## Operations
Create a list with `[]`. For example:
```
["HELLO","WORLD","!",3.14]→Z
Disp Z
```

Use `[]` to index. Adding to the previous code to display "HELLO":
```
Disp Z[0]
```

You can also index strings. Since `Z[1]` is a string:
```
Disp Z[1][2]
```
That prints the `char` `W`, since `Z[1]` == `"WORLD"`, and index `[2]` refers to
the `'R'`.

You can store to a list element, but that is kind of broken:
```
3.14159→Z[3]
```

You can't overwrite with a different-sized element, so Parsnip will make an
attempt to fit it to the size. For example, if you try to write a float to a
ui16, Parsnip  will convert the float to a ui16.

Strings are strange, if you initially store a 5-character string to an element,
all future strings stored to it must fit within 5 characters. Storing to list
elements will eventually change, and elements will be resized according to the
new type, but for now, this is what you have to work with.

## Math Operators
I have programmed in:
* `→`, store the value to a var. Currently allows single-character names, A through Z and theta.
* `+`
* `-`
* `*`
* `/`, currently returns a fixed 16.16 if not an integer.
* `^`, returns a float
* `√(`, returns a float
* `e^(`, returns a float
* `ln()`, returns a float
* <sup>`2`</sup> (squared)
* <sup>`3`</sup> (cubed)
* <sup>`-1`</sup>, returns a float
* `int(val)` converts to a 32-bit unsigned integer, or 16-bit unsigned if small enough.
* `(-)`, negation.
* `=`
* `≠`
* `>`
* `≥`
* `<`
* `≤`

## ""
`"string"` is a string and must have a closing quote.

## Lbl, Goto
These work as in TI-BASIC, but you can be more creative with the names. In the
future, the allowed chars will probably be restricted to alphanumeric.

## Repeat loop
Works like in TI-BASIC.

## While loop
Works like in TI-BASIC.

## If... [ElseIf]... [Else]... End
If you want code to execute only if a `condition` is `true`:
```
:If <<condition>>
:<<code>>
:End
```

For example, suppose you want to increment `x` if `[Enter]` is pressed (note
that `[Enter]` is a [`getKey()`](#getkey) value of 9):
```
:If getKey(9)
:x+1→x
:End
```
*(this is not the most efficient way, you can do `x+getKey(9)→x`)*

If you want to display `"Hello"` if `K`=0, or `"World"` otherwise, you can use
`Else`:
```
:If K=0
:Disp "Hello"
:Else
:Disp "World"
:End
```

If you want to display `"Hello"` if `K`=0, and `"World"` if `K`=1, you can use
`ElseIf`. Note that there are more efficient ways to do this particular example:
```
:If K=0
:Disp "Hello"
:ElseIf K=1
:Disp "World"
:End
```
*At this stage of the parser, `ElseIf` is the `Else` token followed by the `If`
token.*

If you want to display `"Hello"` if `K`=0, `"World"` if `K`=1,
and `":)"` otherwise, then you can use `Else` with `ElseIf`
```
:If K=0
:Disp "Hello"
:ElseIf K=1
:Disp "World"
:Else
;Disp ":)"
:End
```

## ClrDraw, ClrHome
These work basically like in TI-BASIC, but of course ClrDraw doesn't also update
the LCD (like how Axe and Grammer do it).

## DispGraph
Copies the contents of the graph screen to the LCD.

## Disp
Displays a value on the homescreen.

## Text()
`Text(Y,X,value)`
Displays a value on the graph screen at pixel coordinates, using a small font.

***NOTE:** This might change in the future, specifically the default font and coordinate system for text.*

## Pause
Waits for `[Enter]` to be pressed.

## getKey()
`getKey()` returns the current key press.
`getKey(val)` returns `true` if the key is being pressed, else `false`.

## raw()
`raw("hexadecimal string")` converts a string of hexadecimal digits to raw
bytes. Currently useful for sprite data

## Sprite()
`Sprite(raw,y,x,method)` draws an 8x8 sprite using the first 8 bytes of `raw` at
(`y`,`x`) pixel coordinates, using `method`:
* 0 - Overwrite
* 1 - AND logic
* 2 - XOR logic
* 3 - OR logic
* 5 - Erase logic

***NOTE:*** *In the future, this will change; in particular, a `raw` type
variable will not be used.*

## Pixel-On() -Off() -Change() -Test()
Works like in TI-BASIC, except `pxl-Test()` returns `true`/`false` instead of
`1`/`0`. (However, for math purposes, `true` and `false` evaluate to 1 and 0.)


## Full
Sets 15MHz mode. TI-BASIC automatically sets 15MHz mode.

## Fix
Works similar to TI-BASIC, but not the same. This sets the max number of digits
when displaying a float.

## Version
This returns the string containing Parsnip's version. Example usage:

```
Disp VERSION
```

## Get/Set Modes
These functions aren't useful and are almost certain to change in functionality.

`GETMODE()` returns an integer that represents the current mode.
`SETMODE(val)` sets the mode.
The current modes (and these will almost certainly change):

- 1 : InvertTextFlag - Inverts text drawn to the graph screen.
- 2 : InvertLCDFlag - `Dispgraph` inverts the data before outputting to the LCD.
- 4 : OnBlockFlag - Disables checking for the `[ON]` key to exit

Add their values to set multiple modes. For example, to set all three:
```
SETMODE(7)
```

## Set Font
`SETFONT(val)` can be used to set a font to be used on the graph screen. *The
syntax of this command is almost certain to change in the future. Fonts may
change. Font alignment may change.*

- `SETFONT(0)` is a small font (4x6). Text columns are aligned to 4 pixels. That
means, for example, `Text(Y,1,"?"` will draw at pixel coordinates x=4, and
`Text(Y,3,"?"` will draw at pixel coordinates x=12, and so on.
- `SETFONT(1)` this is a variable-width large font.
- `SETFONT(2)` this also uses the small font, but you can draw text to pixel coordinates. **Default**


## LCD commands
The built-in var, `LCD` is a `display` type. On the TI-83+/84+ series, you can:
- `LCD.OFF()` to turn the LCD off
- `LCD.ON()` to turn the LCD on
- `LCD.CONTRAST(val)` to set teh contrast (0 to 63)
- `LCD.ZSHIFT(val)` to set the z-shift value (0 to 63, if you don't know what this is, definitely play with this.
- `LCD.FLIP(val)` on *some* calculators, the LCD has special commands to flip
the LCD horizontally and vertically. This could be useful, but remember that not
all calcs have this.

I don't know how useful this is, but you can also do something like `LCD→Z`,
which means now you can use any of the commands via `Z`.

## CHAR()
`CHAR(val)` converts `val` to a char. For example, to display the `@` symbol:
```
Disp CHAR(64)
```

Or if you want to put an `'@'` before the string "HELLO":
```
Disp CHAR(64)+"HELLO"
```

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
* `raw` is for raw data. Currently, this is what the sprite routine requires.

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

## If
Currently very limited. It can only conditionally execute one line of code.
`Then` and `Else` are not yet supported, and `End` isn't used by this.

## ClrDraw, ClrHome
These work basically like in TI-BASIC, but of course ClrDraw doesn't also update
the LCD (like how Axe and Grammer do it).

## DispGraph
Copies the contents of the graph screen to the LCD.

## Disp
Displays a value on the homescreen.

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

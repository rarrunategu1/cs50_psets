# Questions

## What's `stdint.h`?

stdint.h is a header file in the C standard library that allows programmers to write more
portable code by providing a set of typedefs that specify exact-width integer types, together with
defined min and max allowable values for each type using macros

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

It determines the length of bits for a type of unsigned or signed integer

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A BYTE is 1 byte?? , DWORD is 4 bytes, LONG is 4 bytes , WORD is 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

in ASCII it's the 'B' 'M', in hexadecimal 0x42 0x4D

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the entire bmp file including headerfiles.
biSize is the size of BITMAPINFOHEADER header file which is constant and equal 40 bytes.

## What does it mean if `biHeight` is negative?

A negative biHeight means the image is top-down

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

if the input or ouput file pointers are null (holds no value)

## Why is the third argument to `fread` always `1` in our code?

1 is how large each unit of information will be

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

it assigns -1

## What does `fseek` do?

fseek allows you to rewind or fast-forward within a file

## What is `SEEK_CUR`?

a constant in the FSEEK function that moves file pointer position to given location

## Whodunit?

Professor Plum in the library with the candlestick

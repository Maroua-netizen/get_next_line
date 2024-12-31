# get_next_line

This project is about programming a function that returns a line read from a file descriptor. It is written in C.

## Features
- Reads a line from a file descriptor.
- Handles different buffer sizes.
- Efficient memory management.

## Installation

To compile the `get_next_line` function, use the following command:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c -o get_next_line
```
Replace <size> with the desired buffer size.

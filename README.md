<div align=center >
<h1>Get_next_line</h1>
</div>
<p align="center">
    <img src="https://user-images.githubusercontent.com/102881479/215228915-72cdc235-c3b5-4793-be79-e5e2f36d8336.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/surfi89/get_next_line?color=blue" />
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

---

## 💡 About the project

> _The aim of this project is to make you code a function that returns a line, read from a file descriptor._

_Because reading a line from a fd is way too tedious_, this project is about creating your own function that returns a line read from one file descriptor or more, if you consider the bonus project requirement. The function get_next_line() returns NULL, if there is nothing else to read or if an error occurred. It should work as expected both when reading a file and when reading from the standard output.

The main objetive of this project is to make students learn about **static variables**.

For more detailed information, look at the [**subject of this project**](https://github.com/mouadd55/Get_next_line-42Cursus/blob/9c45205f1d50f362e657741ca916e31f6288276f/get_next_line.pdf).

## How it was implemented

There are many ways to solve the problem stated. Either using an array or a singly linked list as a data structure. I decided to implement the first one.

The project contains six files. The ones that ends with `_bonus` are the bonus project that reads a line from two or more file descriptors at the same time. To sum up,

- `get_next_line.h`: contains the prototypes of all necessary functions to the project.
- `get_next_line.c`: it has five functions. They are:
  - `get_next_line()`: it's the project main function. 
  - `read_line()`: reads a line at a max length of _BUFFER_SIZE_ which is defined at compilation time and creates a line by joining read buffer sized chunks of a line until `EOF` or `\n` is encountered. If _BUFFER_SIZE_ is not defined, the program sets the standard buffer value to 5;
  - `ft_substr()`: takes the full line which contains the '\n' and create a substring from the beginning of the line until the '\n' ('\n' is included in the substring) and returns a clean line.
  - `save_rest()`: if a buffer sized chunk has `\n`, the function will save the content after `\n` to create the next line of the file descriptor by the time the `get_next_line()` function is called again. That's the reason why we need a static variable, the information isn't lost by the time the function ends.
- `get_next_line_utils.c`: implements helper functions to manipulate heap(or dynamic) memory.

## How to use the project

To use the `get_next_line()` in your project it's necessary to include the three files mentioned above to be compiled, either the mandatory or the bonus files, and be sure to include the following flags:

```
$> gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<length> <files>.c
```

Where _\<length\>_ can be substituted by the number of bytes read at a time into the buffer for the read function. If _BUFFER_SIZE_ is not defined, it will be defined to 5 as standard value for the buffer size.

To reference the `get_next_line()` function inside your project, don't forget to add the header:

```c
#include "get_next_line.h"
```

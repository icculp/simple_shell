# Simple Shell Partner Project

Create Unix Command Line Interpreter: s_hell functions like sh

s_hell presents a commmand line allowing user interface with the operating system through keyboard input

## Getting Started

Access Github for s_hell source code:

```
https://github.com/icculp/simple_shell
```

### Prerequisites

Clone github repository:

```
git clone https://github.com/icculp/simple_shell
```

Check all necessary files from repository are available locally:
```
_getenv.c
builtins.c
commandparser.c
env.c
helpers.c
pathparser.c
s_hell.c
strings.c
shellhead.h
```

### How to Use

Change local directory to simple_shell:

```
$ cd simple_shell
```

Compile all necessary files locally:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o s_hell
```

Run compiled executable to enter shell:

```
$ ./s_hell
```

## Built-Ins:
s_hell supports the following built-in commands:

* env - prints environment variable

```
s_hell$ env
```

* exit - exits shell/s_hell program

```
s_hell$ exit
```

### What to Expect:

s_hell functions like a Unix command line interpreter in some of its simplest forms.

To print path of current working directory, try command pwd:

```
s_hell$ pwd
```

To list contents of current working directory, try command ls:

```
s_hell$ ls
```

To list contents of current working directory in long format, try command ls -l:

```
s_hell$ ls -l
```

To print input to screen, try command echo:

```
s_hell$ echo "Holberton School"
Holberton School
s_hell$
```

## Authors

* **Ian Culp** - ian.culp@holbertonschool.com
* **Staci Aaenson-Fletcher** - staci.aaensonfletcher@holbertonschool.com

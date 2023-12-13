# Simple Shell

This is a Simple Shell program implemented in the C programming language. It provides a basic c
ommand-line interface where users can enter commands and have them executed by the
shell.

## Features

- Read input from the user and parse it into command and arguments.
- Execute external commands using the `execvp` function.
- Support for buit-in commands such as `cd` (change directory) and `exit`.
- Parent process waits for the child process to finish executing a command.
- Continous loop for accepting and executing commands until the user decides to exit.

## Getting Started

To get started with the Simple Shell, follow these steps:

1. Clone the repository:

```git clone https://github.com/reinareign/simple_shell.git```

2. Compile the source code:

```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```

3. Run the shell:

```$ ./hsh```

4. You can now enter commands and see them executed by the shell.

## Usage

Once you have the Simple Shell running, you can enter commands just like you would in a regular shell. Here are a few examples:

- Run in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

- Run in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## License

This project is licensed under the MIT License (LICENSE).

## Acknowledgements

This project was developed as a collaboration between [Chisom Enem](https://github.com/reinareign) and [Gad Nwala](https://github.com/DammyNova7) in the [ALX Software Engineering Program](https://www.alxafrica.com/software-engineering/). We would like to acknowledge the joint effort and contributions made by both team members in creating this Simple Shell.

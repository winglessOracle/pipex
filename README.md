# pipex | CODAM Amsterdam

### Table of Contents

* [Introduction](#introduction)
* [How it Works](#how-it-works)
* [Technical Issues](#technical-issues)
* [Summary](#summary)

## Introduction
pipex is a program that allows us to emulate the behavior of the shell pipeline by redirecting the input and output of a command sequence. The program takes as input two files and two commands, and it will execute the two commands using the input file as the standard input and the output file as the standard output.
pipex is an assignment for CODAM in which we are tasked to recreate the pipe command. 

### Requirements
The program should execute as follows:
`./pipex file1 cmd1 cmd2 file2`
where file1 is the input file, file2 is the output file, and cmd1 and cmd2 are the commands to be executed.

It must behave exacly the same as the shell command:
`$> < file1 cmd1 | cmd2 > file2`

As part of the bonus the program can take more than two commands.
and is able to accept the `here_doc` parameter like this"
`$> ./pipex here_doc LIMITER cmd cmd1 file`

This behaves the same as `cmd << LIMITER | cmd1 >> file`

## How it workes
The pipex program works by creating a series of pipes that are used to communicate between the different commands. It first checks the arguments passed to the program and performs error checking to ensure that the input and output files are valid and that the commands can be executed.

Next, it creates a series of forks that execute the individual commands, with each fork executing one command. Each fork is responsible for setting up the appropriate input and output redirection using the pipes that were created earlier.

Once all the forks have completed executing their respective commands, the program waits for all the child processes to terminate and then exits.

## Functionality
- The `check_params` function is called to verify that the correct number of arguments have been passed in and that the necessary input and output files have the proper permissions.
- The `make_pipes` function is called to create the necessary number of pipes for inter-process communication.
- The `create_forks` function is called to create a new process for each command to be executed, and to set up the necessary file descriptors for input and output using the pipes.
- The `find_exec_cmd` function is called to execute each command in the correct process, using the provided environment variables.
- The `get_exit_st` function is called to retrieve the exit status of each process that was created.
- The `close_all_pipes` function is called to close all pipes and free any dynamically allocated memory.

## Error handling
If any errors occur during the setup or execution of the pipex function, appropriate error messages are printed to stderr and the function exits with a non-zero status code.

March, 2021

For more information visit: [Codam.nl](https://codam.nl/) or [42 Cursus Subjects](https://github.com/Surfi89/42cursus/tree/main/Subject%20PDFs).

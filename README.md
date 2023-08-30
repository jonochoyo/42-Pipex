# 42-Pipex

## Introduction

This project is about handling pipes in C.

## Mandatory Part

|Program name        |pipex                                                                                   |
|--------------------|----------------------------------------------------------------------------------------|
|Turn in files:      |Makefile, *.h, *.c                                                                      |
|Makefile  :         |NAME, all, clean, fclean, re                                                            |
|Arguments:          |file1 cmd1 cmd2 file2                                                                   |
|External functions: |ft_printf, open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid                                                                                         |
|Libft authorized    |Yes                                                                                     |
|Description:        |This project is about handling pipes.                                                   |

The program will be executed as follows:  
`./pipex file1 cmd1 cmd2 file2`

It must take 4 arguments:  
• *file1* and *file2* are **file names**.  
• *cmd1* and *cmd2* are **shell commands** with their parameters.

It must behave exactly the same as the shell command below:  
`$> < file1 cmd1 | cmd2 > file2`

For example:  
`$> ./pipex infile "ls -l" "wc -l" outfile`  
Should behave like:  
`< infile ls -l | wc -l > outfile`

- We have to turn in a Makefile which will compile the source files. It must not relink.
- We have to handle errors thoroughly. In no way the program should quit unexpectedly (segmentation fault, bus error, double free)
- The program mustn’t have memory leaks.
- If there is any doubt, handle the errors like the shell command:
`< file1 cmd1 | cmd2 > file2`

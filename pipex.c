/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:58:45 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/08 17:32:41 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// Not allowed
#include <string.h>

// Pending to write function that iterates through the environment variables.
// Once it finds PATH=, gets all the available paths in an array of strings
// It checks if the first command can be found in one of the paths
// If can be found, it runs the program with all the flags (separated by space)
// To get all the flags will need an array that starts with the path, and then has all the flags as separate elements (:)
// The array of the path and flags is NULL terminated too.  

/*
Test for pipex working without envp.
Programs are set and won't read the user input arguments.
Program can read user input for infile and outfile
-Create pipe with two fd
-Fork into parent and child
*/

int	main(int argc, char *argv[], char *envp[])
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
	pid_t	pid;
	int		child_fd;
	int		parent_fd;

	if (argc != 5)
		return(0);
	infile = argv[1];
	outfile = argv[4];
	cmd1 = argv[2];
	cmd2 = argv[3];

	// We have to find the correct path for the command input by the user
	// Testing if user inputs ls, we will assign the path to ls
	// If no input, default to cat
	// May need to create an array of strings where the first string
	// is the path and the rest the flags so that can be the input for execve
	char *path;
	
	// change to use my own strcmp
	if (strcmp(cmd1, "ls") == 0)
		path = "/bin/ls";
	else
		path = "/bin/cat";
	
	// if cannot access the program or is not an executable we exit.
	if (access(path, F_OK | X_OK) != 0)
		exit(1);

	char	*cmd11[] = {path, NULL};
	char	*cmd22[] = {"/usr/bin/wc", NULL};

	int	pipe_fd[2];
	if (pipe(pipe_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	// 	CHILD
	// -If its child, we make the first command run there by taking
	// input from the infile and assigning it as STDIN. 
	// -In the child, we will assing the output to be the write end 
	// of the pipe
	// -We ensure fds from pipe and child are closed
	// -Execute cmd1 in the child using infile.
	if (pid == 0)
	{
		child_fd = open(infile, O_RDONLY);
		// Make stdin to be the infile
		dup2(child_fd, STDIN_FILENO);
		close(child_fd);
		// Make stdout to be the pipe write end
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		// Execute command 1
		int val_child = execve(cmd11[0], cmd11, NULL);
		if (val_child == -1)
			perror("Error");
	}
	// PARENT
	// -Make the parent wait for the child to finish
	// -Open the outfile
	// Make the input for parent to be the pipe read end.
	// close pipe write end
	// Make the output of parent to be the outfile
	// close parent_fd
	// execute cmd22 for parent so it outputs to the outfile by using
	// the pipe read end as input.
	if (pid > 0)
	{
		wait(NULL);
		parent_fd = open(outfile, O_WRONLY | O_CREAT, 0777);
		// Make input to be the pipe read end
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[1]);
		// Make output to be the outfile
		dup2(parent_fd, STDOUT_FILENO);
		close(parent_fd);
		int val_parent = execve(cmd22[0], cmd22, NULL);
		if (val_parent == -1)
			perror("Error");
	}
	return (0);
}
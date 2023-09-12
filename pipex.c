/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:58:45 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/12 16:52:07 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

// 	CHILD (Working, need to add envps)
// -If its child, we make the first command run there by taking
// input from the infile and assigning it as STDIN. 
// -In the child, we will assign the output to be the write end 
// of the pipe
// -We ensure fds from pipe and child are closed
// -Execute cmd1 in the child using infile.
void	child(char *infile, int *pipe_fd, char *cmd11[])
{
	int	in_fd;
	int val_child;

	in_fd = open(infile, O_RDONLY);
	if (in_fd == -1)
	{
		perror("Open infile error:");
		exit(1);
	}	
	// Make stdin to be the infile
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	// Make stdout to be the pipe write end
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	// Execute command 1
	val_child = execve(cmd11[0], cmd11, NULL);
	if (val_child == -1)
		perror("Executing child error:");
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
void	parent(char *outfile, int *pipe_fd, char *cmd22[])
{
	int	out_fd;
	int	val_parent;

	wait(NULL);
	out_fd = open(outfile, O_WRONLY | O_CREAT, 0777);
	if (out_fd == -1)
	{
		perror("Open outfile error:");
		exit(1);
	}		
	// Make input to be the pipe read end
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	// Make output to be the outfile
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd); 
	val_parent = execve(cmd22[0], cmd22, NULL);
	if (val_parent == -1)
		perror("Executing parent error:");
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd1;
	char	*cmd2;
	pid_t	pid;

	if (argc != 5)
	{
		perror("Invalid input:");
		exit(1);
	}
	cmd1 = argv[2];
	cmd2 = argv[3];
	// We have to find the correct path for the command input by the user
	// Testing if user inputs ls, we will assign the path to ls
	// If no input, default to cat
	// May need to create an array of strings where the first string
	// is the path and the rest the flags so that can be the input for execve
	char *path;
	if (ft_strncmp(cmd1, "ls", 2) == 0)
		path = "/bin/ls";
	else
		path = "/bin/cat";
	// if cannot access the program or is not an executable we exit.
	if (access(path, F_OK | X_OK) != 0)
		exit(1);

	char	*cmd11[] = {path, NULL};
	char	*cmd22[] = {"/usr/bin/wc", "-l", NULL};

	int	pipe_fd[2];
	if (pipe(pipe_fd) == -1)
		exit(1);

	pid = fork();
	if (pid == -1)
		exit(1);

	if (pid == 0)
	{
		//argv[1] is infile
		child(argv[1], pipe_fd, cmd11);
	}
	if (pid > 0)
	{
		//argv[4] is outfile
		parent(argv[4], pipe_fd, cmd22);
	}
	return (0);
}
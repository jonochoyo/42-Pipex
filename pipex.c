/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:58:45 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/07 17:47:42 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

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
	
	char	*cmd11[] = {"/bin/cat", NULL};
	char	*cmd22[] = {"/usr/bin/grep", "world", NULL};

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
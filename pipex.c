/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:58:45 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/27 10:38:30 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
- Child process: Opens infile and checks for errors
- Dups infile fd into STDIN
- Dups pipe write end into STDOUT
- Closes open fd that are no longer needed
- Executes cmd1
*/
static void	child_prcs(char *infile, int *pipe_fd, char *cmd, char *envp[])
{
	int	in_fd;

	in_fd = open(infile, O_RDONLY);
	if (in_fd == -1)
	{
		perror("Open infile error");
		exit(1);
	}
	dup2(in_fd, STDIN_FILENO);
	close(in_fd);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	execute_cmd(cmd, envp);
}

/*
- Parent process: Opens outfile and checks for errors
- Waits for Child to finish
- If outfile doesn't exist, is created in truncate mode and 666 permissions
- Dups pipe read end fd into STDIN
- Dups outfile into STDOUT
- Closes open fd that are no longer needed
- Executes cmd2
*/
static void	parent_prcs(char *outfile, int *pipe_fd, char *cmd, char *envp[])
{
	int	out_fd;

	wait(NULL);
	out_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (out_fd == -1)
	{
		perror("Open outfile error");
		exit(1);
	}
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	dup2(out_fd, STDOUT_FILENO);
	close(out_fd);
	execute_cmd(cmd, envp);
}

/*
- Main function: Checks for argc = 5
- Creates the pipe for child and parent
- Forks into child and parent
- Runs the child and parents processess
- argv[1]: infile, argv[2]: cmd1, argv[3]: cmd2, argv[4]: outfile
*/
int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		pipe_fd[2];

	if (argc != 5)
	{
		ft_putendl_fd("Invalid input. Try: ./pipex file1 cmd1 cmd2 file2", 1);
		exit(1);
	}
	if (pipe(pipe_fd) == -1)
	{
		perror("Could not create pipe");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Error while forking");
		exit(1);
	}
	if (pid == 0)
		child_prcs(argv[1], pipe_fd, argv[2], envp);
	if (pid > 0)
		parent_prcs(argv[4], pipe_fd, argv[3], envp);
	return (0);
}

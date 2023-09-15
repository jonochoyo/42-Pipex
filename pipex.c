/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:58:45 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/15 16:59:55 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Pending to write function that iterates through the environment variables.
// Once it finds PATH=, gets all the available paths in an array of strings
// It checks if the first command can be found in one of the paths
// If can be found, it runs the program with all the flags (separated by space)
// To get all the flags will need an array that starts with the path, and then 
//has all the flags as separate elements (:)
// The array of the path and flags is NULL terminated too.  

// Function to get the path of the command in the env variables PATH
// Iterates through the envp's until find PATH
// Split PATH variable into all_paths with split showing all available paths
// Join / with the cmd to then join with a path to check if the cmd exists
// and can be run with access. If it does, we return the full path. 
// Otherwise we free the created things and return NULL if command not found. 
char	*get_path(char *cmd, char *envp[])
{
	int		i;
	char	**all_paths;
	char	*tmp;
	char	*path;

	i = 0;
	while (envp[i] != 0 && (ft_strncmp(envp[i], "PATH=", 5) != 0))
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	tmp = ft_strjoin("/", cmd);
	i = 0;
	while (all_paths[i])
	{
		path = ft_strjoin(all_paths[i], tmp);
		if (access(path, F_OK | X_OK) == 0)
		{
			free(tmp);
			return (path);
		}
		free(path);
		i++;
	}
	return (NULL);
}

void	execute_cmd(char *cmd, char *envp[])
{
	char	*path;
	char	**cmd_flags;

	cmd_flags = ft_split(cmd, ' ');
	path = get_path(cmd_flags[0], envp);
	if (path == NULL)
	{
		perror("Command not found:");
		exit(1);
	}
	if (execve(path, cmd_flags, envp) == -1)
	{
		perror("Could not execute the command");
		free(cmd_flags);
		free(path);
		exit(1);
	}
	free(cmd_flags);
	free(path);
}

// Function to execute the command
// Split the input cmd into an array of strings with the cmd and flags

// 	CHILD (Working, need to add envps)
// -If its child, we make the first command run there by taking
// input from the infile and assigning it as STDIN. 
// -In the child, we will assign the output to be the write end 
// of the pipe
// -We ensure fds from pipe and child are closed
// -Execute cmd1 in the child using infile.
void	child_prcs(char *infile, int *pipe_fd, char *cmd, char *envp[])
{
	int	in_fd;

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
	execute_cmd(cmd, envp);
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
void	parent_prcs(char *outfile, int *pipe_fd, char *cmd, char *envp[])
{
	int	out_fd;

	wait(NULL);
	out_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
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
	execute_cmd(cmd, envp);
}

//argv[1]: infile
//argv[2]: cmd1
//argv[3]: cmd2
//argv[4]: outfile
int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		pipe_fd[2];

	if (argc != 5)
	{
		perror("Invalid input: Try: ./pipex file1 cmd1 cmd2 file2");
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
		perror("Error while forking:");
		exit(1);
	}
	if (pid == 0)
		child_prcs(argv[1], pipe_fd, argv[2], envp);
	if (pid > 0)
		parent_prcs(argv[4], pipe_fd, argv[3], envp);
	return (0);
}

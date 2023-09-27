/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:04:12 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/27 10:37:28 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
- Function to get the path of the command in the envp PATH
- Iterates through the envp's until find PATH=
- Splits the PATH into an array of strings holding all available paths all_paths
- Creates a tmp variable to hold '/' + cmd 
- Iterates through all_paths and creates a full path to check if can be accessed
- If it can be accessed and executed, frees the tmp and returns the path
- Otherwise, returns NULL when command not found
*/
static char	*get_path(char *cmd, char *envp[])
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

/*
- Function to execute the commands
- Splits the input cmd into an array of strings for the cmd and flags
- Finds the cmd path with get_path()
- If it finds a path, executes the cmd, otherwise prints error and exits. 
*/
void	execute_cmd(char *cmd, char *envp[])
{
	char	*path;
	char	**cmd_flags;

	cmd_flags = ft_split(cmd, ' ');
	path = get_path(cmd_flags[0], envp);
	if (path == NULL)
	{
		perror("Command not found");
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

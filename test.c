/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:29:23 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/06 19:17:00 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Testing how pipe and fork work with wait().
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define MSGSIZE 16

int	main(void)
{
	char	inbuf[MSGSIZE];
	int		fd[2];
	int		i;
	char	*msg1;
	char	*msg2;
	char	*msg3;
	pid_t	pid;

	msg1 = "hello world #1";
	msg2 = "hello world #2";
	msg3 = "hello world #3";

	/* Use dup2 to duplicate the stdout output into fd1 */
	int fd1 = open("test.txt",O_WRONLY);
	dup2(fd1 , STDOUT_FILENO);

	if (pipe(fd) < 0)
		exit(1);
	/* write pipe */
	write(fd[1], msg1, MSGSIZE);
	write(fd[1], msg2, MSGSIZE);
	write(fd[1], msg3, MSGSIZE);
	i = 0;
	while (i < 3)
	{
		/* read pipe */
		read(fd[0], inbuf, MSGSIZE);
		printf("%s\n", inbuf);
		// fflush(stdout);
		i++;
	}
	pid = fork();
	if (pid == -1)
		return(-1);
	char	*argv[] = {"/bin/ls", "-l", NULL};
	/* 
	execve() uses an array of strings argv with the filepath of the program
	any flags and is NULL terminated. First argument is the filepath and
	then the full array.

	perror is used for producing a message on standard error. 
	*/
	if (pid == 0)
	{
		// wait(NULL);
		printf("Hello from child\n");
		// fflush(stdout);
		int		val = execve(argv[0], argv, NULL);
		printf("hello");
		// fflush(stdout);
		if (val == -1)
			perror("Error");
	}
	if (pid > 0)
	{
		wait(NULL);
		printf("Hello from parent\n");
	}
	printf("execve did not run\n");
	return (0);
}

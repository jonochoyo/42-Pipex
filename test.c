/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:29:23 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/09/04 17:42:53 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Testing how pipe and fork work with wait().
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
		i++;
	}
	pid = fork();
	if (pid == 0)
	{
		// wait(NULL);
		printf("Hello from child\n");
	}

	if (pid > 0)
	{
		wait(NULL);
		printf("Hello from parent\n");
	}
	printf("%s\n", "testprint");
	return (0);
}

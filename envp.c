#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[], char *envp[])
{
	int	i;

	i = 0;
	int file = open("dup.txt", O_WRONLY | O_CREAT, 0777);
	dup2(file, STDOUT_FILENO);
	close(file);
	printf("%s\n", envp[4]);
	while(envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
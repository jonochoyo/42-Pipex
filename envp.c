#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	int	i;

	i = 0;
	while(envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
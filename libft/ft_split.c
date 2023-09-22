/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:30:10 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/11 14:30:11 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates with malloc and returns an array of strings obtained by splitting ’s’
using the character ’c’ as a delimiter. The array must end with a NULL pointer.

The helper function ft_nwords will iterate through 's' and when it finds a 
char that is not the delimiter it will count a word. It then goes on a while
loop that keeps iterating as long as we haven't reach the end of 's' and have
not found another delimiter. If we reach the \0 we return the nwords counted.
If not reached the end yet, we keep iterating through 's' to keep checking.

ft_split allocates memory for nwords + 1 (NULL pointer) and then iterates from
0 up to nwords with j. During that it iterates through 's' with i and checks
if we find a char that is not the delimiter. In that case we save that index 
to start and have a while loop that goes until the end of the string found. 
Once reach another delimiter or \0 it will create the substring to be assigned
to strs[j] and move to the next word. 
*/

static int	ft_nwords(char const *s, char c)
{
	int	i;
	int	nwords;

	i = 0;
	nwords = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nwords++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				return (nwords);
		}
		i++;
	}
	return (nwords);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**strs;

	strs = (char **) malloc (sizeof(char *) * (ft_nwords(s, c) + 1));
	if (strs == NULL || s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_nwords(s, c))
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			strs[j] = ft_substr(s, start, i - start);
			j++;
		}
		i++;
	}
	strs[j] = NULL;
	return (strs);
}

/*
int	main(void)
{
	// If strings is only a NUL terminator, the while won't run and we will run 
	//ft_substr(s, 0, 0) which will only output a NUL terminator and then 
	//the NULL pointer. 
	// If string is only the separator? Should output two empty words?
	char const	str[] = "a4a44";
	char	c = '4';
	int	i = 0;

	char	**strs = ft_split(str, c);
	if (strs != NULL)
	{
		while (strs[i])
		{
			printf("%s\n", strs[i]);
			i++;
		}
		printf("%s\n", strs[i]);
	}
	else
	{
		printf("Error! Array could not be allocated");
	}
	return (0);
}
*/

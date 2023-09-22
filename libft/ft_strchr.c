/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:27:05 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/12 16:49:26 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strchr() function locates the first occurrence of c (converted to a char)
in the string pointed to by s. If c is `\0', the functions locates it on s. 
RETURN: A pointer to the located character, or NULL if the character is not in s.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *) &(s[i]));
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &(s[i]));
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "Hello World 42";
	int	chr = 'o';

	printf("%p\n", ft_strchr(str, chr));
	printf("%c\n", *ft_strchr(str, chr));
	printf("%p\n", strchr(str, chr));
}
*/

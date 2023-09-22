/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:28:00 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/21 15:00:06 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strncmp() function lexicographically compare the strings s1 and s2.
The strncmp() function compares not more than n characters.
The comparison is done using unsigned characters, so that `\200'
is greater than `\0'.
RETURN: An integer greater than, equal to, or less than 0, according as 
the string s1 is greater than, equal to, or less than the string s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	word1[] = "Hell";
	char	word2[] = "Hella";

	printf("%i\n", ft_strncmp(word1, word2, 5));
	printf("%i\n", strncmp(word1, word2, 5));
}
*/

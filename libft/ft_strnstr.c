/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:28:38 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/13 14:17:28 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strnstr() function locates the first occurrence of the null-terminated string
needle in the string haystack, where not more than len characters are searched.
RETURN: If needle is an empty string, haystack is returned; if needle occurs
nowhere in haystack, NULL is returned; otherwise a pointer to the first character
of the first occurrence of needle is returned.

Iterate through haystack with i and compare with needle iterating with j.
While chars are the same on haystack and needle we keep going and if reaches the 
end of needle we can return the pointer to the i position in haystack. 
i keeps the position at where needle started to match with haystack
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *) &(haystack[i]));
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	hay[] = "Hello World 42";
	const char	need[] = "World";
	char		size = 13;

	printf("%s\n", ft_strnstr(hay, need, size));
	printf("%s\n", strnstr(hay, need, size));
}
*/

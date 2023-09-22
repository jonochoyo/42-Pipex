/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:28:27 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/12 17:19:36 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memcmp() function compares byte string s1 against byte string s2.
Both strings are assumed to be n bytes long.
RETURN: The memcmp() function returns zero if the two strings are identical,
otherwise returns the difference between the first two differing bytes
(treated as unsigned char values)
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	str1[] = "he";
	char	str2[] = "he";
	int	size = 10;

	printf("%i\n", ft_memcmp("", "", size));
	printf("%i\n", ft_memcmp(str1, str2, size));
	printf("%i\n", memcmp(str1, str2, size));
}
*/

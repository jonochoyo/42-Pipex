/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:28:12 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/12 17:15:30 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memchr() function locates the first occurrence of c 
(converted to an unsigned char) in string s.
RETURN: A pointer to the byte located, or NULL if no such byte exists within n.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[] = "Hello World 42";
	int	ltr = '4';
	size_t	size = 15;

	printf("%p\n", ft_memchr(str, ltr, size));
	printf("%c\n", *(char *)ft_memchr(str, ltr, size));
	printf("%p\n", memchr(str, ltr, size));
	printf("%p\n", &str[12]);
}
*/

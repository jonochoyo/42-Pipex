/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:25:59 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/11 16:47:05 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memcpy() function copies n bytes from memory area src to memory area dst.
If dst and src overlap, behavior is undefined.
RETURN: The memcpy() function returns the original value of dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	d = (char *) dst;
	s = (const char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

/*
int	main(void)
{
	char	source[] = "Hello";
	char	destination[] = "World";
	char	src[] = "Hello";
	char	dst[] = "World";

	printf("%s\n", (char *) ft_memcpy(destination, source, 2));
	printf("%s\n", (char *) memcpy(dst, src, 2));
}
*/

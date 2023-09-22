/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:25:33 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/12 16:14:15 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The memset() function writes len bytes of value c 
(converted to an unsigned char) to the string b.
RETURN: The memset() function returns its first argument.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

/*
int	main(void)
{
	char	str[] = "Hello";

	printf("%s\n", (char *) ft_memset(str, 'Z', 3));
	printf("%s\n", (char *) memset(str, 'Z', 3));
}
*/

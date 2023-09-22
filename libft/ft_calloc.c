/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:29:03 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/20 13:22:42 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The calloc() function contiguously allocates enough space for count objects 
that are size bytes of memory each and returns a pointer to the allocated 
memory. The allocated memory is filled with bytes of value zero.

If nbytes is 0, we make nbytes 1 as calloc from the library returns an address 
with value 0 (ft_bzero does nothing if nbytes is zero). To avoid memory issues, 
we check if nbytes can fit in size_t which can vary depending if its 32 or 
64bit system. We use 32-bit max for safety. 
*/

void	*ft_calloc(size_t count, size_t size)
{
	size_t	max;
	size_t	nbytes;
	void	*ptr;

	max = 4294967295;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count * size > max)
		return (NULL);
	nbytes = count * size;
	ptr = malloc(nbytes);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nbytes);
	return (ptr);
}

/*
int	main(void)
{
	size_t	count = 4294967295;
	size_t	size = 1;
	size_t	i = 0;
	char	*ptr = calloc(count, size);
	char	*ptr2 = ft_calloc(0, 0);

	printf("Return of ft_calloc(0, 0): %p ", ptr2);
	printf("Value: %i\n", *(ptr2));
	while (i < count * size)
	{
		printf("%i, ", ptr[i]);
		printf("index : %zu\n", i);
	 	i++;
	}
}
*/

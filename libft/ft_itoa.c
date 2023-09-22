/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:30:19 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/17 16:32:16 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates with malloc and returns a string representing the integer received 
as an argument. Negative numbers must be handled.

Helper function ft_get_size() gets the length of the number. Checks if it is
negative or zero to have a byte for those cases on the string ('-' or '0')
It divides the number by 10 until it reaches 0 to keep track of the length.

ft_itoa allocates memory for the length and adds 1 for \0. We typecast nb to 
unsigned int nbr so that can hold INT_MIN as positive. Then checks if number is 
negative to put the '-' on the 0th index of the string and if that is the case 
multiplies the nb * (-1) to work with only positive values in nbr.  
If n is 0, we set the first char to '0'. For every case the last char is \0.
The main loop will iterate while nbr is not zero and divide it by 10 on each 
iteration. It will also assign the digit as char to the string at size index.
*/

static int	ft_get_size(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	unsigned int	nbr;

	size = ft_get_size(n);
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr = n * (-1);
	}
	if (nbr == 0)
		str[0] = '0';
	str[size] = '\0';
	while (nbr != 0)
	{
		size--;
		str[size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

/*
int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(2147483647));
}
*/

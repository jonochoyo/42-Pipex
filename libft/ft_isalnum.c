/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:24:08 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/11 15:07:47 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) + ft_isdigit(c));
}

/*
int	main(void)
{
	printf("%i\n", ft_isalnum('z'));
	printf("%i\n", ft_isalnum('9'));
	printf("%i\n", ft_isalnum(' '));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:22:14 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/11 15:05:09 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

/*
int	main(void)
{
	printf("%i\n", ft_isdigit('0'));
	printf("%i\n", ft_isdigit('T'));
	printf("%i\n", ft_isdigit(' '));
}
*/

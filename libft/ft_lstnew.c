/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:57:31 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/19 16:52:43 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates with malloc and returns a new node. The member variable ’content’
is initialized with the value of the parameter ’content’. The variable ’next’
is initialized to NULL.

PARAMETERS: 
content: The content to create the node with. (passed as an address)

RETURN: The new node

We create a new node by allocating memory of size t_list and assigning its 
content to the passed argument and its next value to NULL. 
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

/*
int	main(void)
{
	int		data;
	t_list	*node;

	data = 3;
	node = ft_lstnew(&data);
	printf("%i\n", *(int *)(node -> content));
	printf("%p\n", node -> next);
}
*/
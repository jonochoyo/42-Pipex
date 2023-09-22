/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:42:54 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/20 14:39:34 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Takes as a parameter a node and frees the memory of the node’s content using 
the function ’del’ given as a parameter and free the node. The memory of ’next’ 
must not be freed.

PARAMETERS:
lst: The node to free.
del: The address of the function used to delete the content.

We first check if we have a node and a function, if these are NULL we return.
If we do have arguments to work with, we then use the function del to free the
content of lst and then free the node lst.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/*
void delete(void *data)
{
	free(data);
}

int	main(void)
{
	t_list	*node;
	int	data;

	data = 42;
	node = ft_lstnew(&data);
	printf("Node content is: %i\n", *(int *)node -> content);
	// delete(node -> content);
	ft_lstdelone(node, delete);
	printf("Node content after delete is: %i\n", *(int *)node -> content);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:44:21 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/21 12:43:32 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each node.

PARAMETERS:
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.

First check for NULL arguments to proceed. Then iterate through the list and
apply the function f to the content of each node. 
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void	func(void *data)
{
	*(int *)data = 42;
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	int	data;
	int	data2;

	data = 1;
	data2 = 2;
	node1 = ft_lstnew(&data);
	node2 = ft_lstnew(&data2);

	ft_lstadd_back(&node1, node2);

	printf("Node content is: %i\n", *(int *)node1 -> content);
	printf("Node content is: %i\n", *(int *)node2 -> content);

	ft_lstiter(node1, func);

	printf("Node content is: %i\n", *(int *)node1 -> content);
	printf("Node content is: %i\n", *(int *)node2 -> content);
}
*/

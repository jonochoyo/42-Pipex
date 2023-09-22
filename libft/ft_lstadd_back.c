/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:09:15 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/20 13:00:41 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Adds the node ’new’ at the end of the list.

PARAMETERS:
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.

We check if the address of the pointer to the first node or the new node are
NULL to see if we can proceed. Then if the First node is NULL, we make the new 
node to be the head and only node of the list. Otherwise, if there are already 
nodes, we can save the last node address by using ft_lstlast and then assign 
its next node value to the new node so it becomes the new last.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
	{
		return ;
	}
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

/*
int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	int	data1 = 1;
	int data2 = 2;

	head = (t_list *) malloc(sizeof(t_list));

	node1 = ft_lstnew(&data1);
	node2 = ft_lstnew(&data2);

	printf("Original node1 address: %p\n", node1);
	printf("Original node2 address: %p\n", node2);

	ft_lstadd_front(&head, node1);

	printf("Current head is: %p\n", head);

	ft_lstadd_back(&head, node2);

	printf("ADD NEW NODE TO BACK\n");

	printf("New head is: %p\n", head);
	printf("Last node is: %p\n", ft_lstlast(head));
}
*/

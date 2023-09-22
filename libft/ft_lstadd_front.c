/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:34:44 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/20 13:00:16 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Adds the node ’new’ at the beginning of the list.

PARAMATERS:
lst: The address of a pointer to the first link of a list (pointer to pointer)
new: The address of a pointer to the node to be added to the list.

We first check if arguments are not NULL to proceed. If lst is not empty, and we
have a new node, we can make the new node point to the first node *lst and
then make the new node be the first one by assigning its address to the head *lst
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	**head;
	t_list	*node;

	int	data1 = 1;
	int data2 = 2;

	head = (t_list **) malloc(sizeof(t_list *));
	*head = (t_list *) malloc(sizeof(t_list));
	(*head) -> content = &data1;
	(*head) -> next = NULL;

	node = (t_list *) malloc(sizeof(t_list));
	node -> content = &data2;
	node -> next = NULL;

	printf("Current head is: %p\n", *head);
	printf("New node address: %p\n", node);
	ft_lstadd_front(head, node);
	printf("ADD NEW NODE TO FRONT\n");
	printf("New head is: %p\n", *head);
	printf("Second node is now: %p\n", node -> next);
}
*/
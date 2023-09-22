/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:51:25 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/20 13:11:48 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Counts the number of nodes in a list.

PARAMETERS:
lst: The beginning of the list.

RETURN: Last node of the list

First check if the lst is NULL. If that is the case we return 0 as the list is 
empty. We iterate through the list while the lst is not NULL (end of list). 
On each iteration we count the node adding 1 to size and move to the next node.
*/

int	ft_lstsize(t_list *lst)
{
	int		size;

	if (lst == NULL)
		return (0);
	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/*
int	main(void)
{
	int	data = 3;
	t_list *head = NULL;
	t_list *node = ft_lstnew(&data);
	t_list *node2 = ft_lstnew(&data);
	t_list *node3 = ft_lstnew(&data);
	
	ft_lstadd_front(&head, node);
	ft_lstadd_front(&head, node2);
	ft_lstadd_front(&head, node3);

	printf("%i\n", ft_lstsize(head));
	printf("%i\n", ft_lstsize(NULL));
}
*/

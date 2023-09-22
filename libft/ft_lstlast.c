/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:23:41 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/20 13:25:41 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns the last node of the list.

PARAMETERS:
lst: The beginning of the list.

If lst is not NULL, we iterate while the next node is not NULL. Once we reach 
the node that has the next one as NULL is the last one and we return that.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
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

	printf("%p\n", ft_lstlast(head));
	printf("%p\n", node);
	printf("%p\n", node2);
	printf("%p\n", node3);
}
*/

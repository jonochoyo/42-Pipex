/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoy-me <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:32:08 by jchoy-me          #+#    #+#             */
/*   Updated: 2023/07/21 14:26:54 by jchoy-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Iterates the list ’lst’ and applies the function ’f’ on the content of each 
node. Creates a new list resulting of the successive applications of the 
function ’f’. The ’del’ function is used to delete the content of a node 
if needed.

PARAMETERS:
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
del: The address of the function used to delete the content of a node if 
needed.

RETURN: The new list

First check if arguments are NULL. We then initiate the new list to NULL.
We then iterate through the original list. On each iteration, we create the
newdata and newnode with lstnew. If creating the newnode fails, we clear the
newlst and also free the newdata created before that attempt. 
If allocation succeeds, we then add the newnode at the end of the newlst and
keep iterating. 
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	void	*newdata;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		newdata = f(lst->content);
		newnode = ft_lstnew(newdata);
		if (newnode == NULL)
		{
			ft_lstclear(&newlst, del);
			del(newdata);
		}
		ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}

/*
void	*func(void *data)
{
	*(int *)data = 42;
	return ((void *)(data));
}

void delete(void *data)
{
	free(data);
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

	t_list *newlist = ft_lstmap(node1, func, delete);

	printf("New list: %p\n", newlist);

	printf("New Node content is: %i\n", *(int *)(newlist->content));
	printf("Node content is: %i\n", *(int *)(newlist->next) -> content);
}
*/

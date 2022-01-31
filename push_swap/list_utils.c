/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:13:49 by qduong            #+#    #+#             */
/*   Updated: 2022/01/31 13:15:16 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

pst_list	*ft_lstnew(int value, int rank)
{
	pst_list	*new;

	new = ft_calloc(1, sizeof(pst_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->rank = rank;
	(*new).next = NULL;
	new->previous = NULL;
	return (new);
}

pst_list	*ft_lstlast(pst_list *lst)
{
	pst_list	*first;
	pst_list	*last;

	if (!lst)
		return (NULL);
	first = lst;
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	lst = first;
	return (last);
}

void	ft_lstadd_back(pst_list **lst, pst_list *new)
{
	pst_list	*current;

	current = *lst;
	if (lst)
	{
		if (*lst)
		{
			while (current -> next != NULL)
			{
				current = current -> next;
			}
			current -> next = new;
			new-> previous = current;
		}
		else
			*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 1;
	if (lst)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
			len++;
		}
	}
	else
		return (0);
	return (len);
}

void	ft_lstclear(pst_list **lst)
{
	pst_list	*current;
	pst_list	*following;

	current = *lst;
	if (lst)
	{
		while (current -> next != NULL)
		{
			following = current-> next;
			free(current);
			current = following;
		}
		*lst = NULL;
	}
	return ;
}

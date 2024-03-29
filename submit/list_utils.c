/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:13:49 by qduong            #+#    #+#             */
/*   Updated: 2022/04/10 13:03:26 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_st_list	*ft_lstnew(int value, int rank)
{
	t_st_list	*new;

	new = ft_calloc(1, sizeof(t_st_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->rank = rank;
	(*new).next = NULL;
	new->previous = NULL;
	return (new);
}

t_st_list	*ft_lstlast(t_st_list *lst)
{
	t_st_list	*first;
	t_st_list	*last;

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

void	ft_lstadd_back(t_st_list **lst, t_st_list *new)
{
	t_st_list	*current;

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
			new -> previous = current;
		}
		else
			*lst = new;
	}
}

int	ft_lstsize(t_st_list *lst)
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

void	ft_lstclear(t_st_list **lst)
{
	t_st_list	*current;
	t_st_list	*following;

	current = *lst;
	if (lst)
	{
		while (current -> next != NULL)
		{
			following = current-> next;
			free(current);
			current = following;
		}
		free(current);
		*lst = NULL;
	}
	return ;
}

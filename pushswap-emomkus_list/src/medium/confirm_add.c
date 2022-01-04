/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirm_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:30:45 by emomkus           #+#    #+#             */
/*   Updated: 2022/01/04 15:14:51 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
	Functions to check errors, before adding to back of list.
	Integer pointer address temporary stores integer. Address then is stored
	into list if integer is valid.
	If integer is not number or integer is ussed before ft_confirm_add return
	zero.
*/

int		ft_unused_check(t_list *lst, int num, int *address)
{
	int	*comp;

	while (lst->next != 0 && address != lst->content)
	{
		comp = lst->content;
		if (comp[0] == num)
			return (0);
		lst = lst -> next;
	}
	return (1);
}

//comment by Huy: Need more checks - duplicate checks and empty string "" check!

int		valid_num_check(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_confirm_add(char *num, t_list **stack_a)
{
	int	*num_int;

	if (valid_num_check(num))
	{
		num_int = ft_calloc(1, sizeof(int));
		num_int[0] = ft_atoi(num);
		ft_lstadd_back(stack_a, ft_lstnew(num_int));
	}
	else
		return (0);
	return (ft_unused_check(*stack_a, num_int[0], num_int));
}
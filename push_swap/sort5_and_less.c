/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5_and_less.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 18:59:11 by qduong            #+#    #+#             */
/*   Updated: 2022/04/09 19:04:11 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	sort3(pst_list **stack)
{
	while (!check_stack_if_sorted(stack))
	{
		if ((*stack)-> rank == 2 && \
		(*stack)->next->rank == (*stack)-> rank - 2 \
		&& (*stack)->next->next->rank == (*stack)-> rank - 1)
		{
			rotate(stack, 'a');
			return ;
		}
		if ((*stack)->rank > (*stack)->next->rank)
			swap(stack, 'a');
		else
			r_rotate(stack, 'a');
	}
	// printf("Sort 3 Done!\n");
	return ;
}

void	sort5(pst_list **stacka, pst_list **stackb)
{
	push_specific(stacka, stackb, 0);
	push_specific(stacka, stackb, 1);
	sort3(stacka);
	push(stackb, stacka, 'a');
	push(stackb, stacka, 'a');
	return ;
}

//For sort 4: You push the index 0 to B, sort 3 and push back

void	sort4(pst_list **stacka, pst_list **stackb)
{
	push_specific(stacka, stackb, 0);
	sort3(stacka);
	push(stackb, stacka, 'a');
	return ;
}

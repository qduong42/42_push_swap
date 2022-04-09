/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:32:03 by qduong            #+#    #+#             */
/*   Updated: 2022/04/09 23:35:12 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_aux_2(t_st_list **stack1, t_st_list **stack2)
{
	(*stack2)->previous = *stack1;
	(*stack1)->next = (*stack2);
	(*stack2) = (*stack1);
	(*stack1) = NULL;
	return (1);
}

static int	push_aux_1(t_st_list **stack1, t_st_list **stack2)
{
	(*stack1) = (*stack1)->next;
	*stack2 = (*stack1)->previous;
	(*stack1)->previous = NULL;
	(*stack2)->previous = NULL;
	(*stack2)->next = NULL;
	return (1);
}

static int	push_aux_3(t_st_list **stack1, t_st_list **stack2)
{
	(*stack1) = (*stack1)->next;
	(*stack2)->previous = (*stack1)->previous;
	(*stack1)->previous->next = (*stack2);
	(*stack1)->previous = NULL;
	(*stack2) = (*stack2)->previous;
	return (1);
}

int	push(t_st_list **stack1, t_st_list **stack2, char a)
{
	int	i;
	int	y;

	i = ft_lstsize(*stack2);
	y = ft_lstsize(*stack1);
	if (i == 0)
	{
		push_aux_1(stack1, stack2);
	}
	else if (y == 1)
	{
		push_aux_2(stack1, stack2);
	}
	else
	{
		push_aux_3(stack1, stack2);
	}
	if (a == 'a')
		write(1, "pa\n", 3);
	else if (a == 'b')
		write(1, "pb\n", 3);
	return (1);
}

//function to push a specific rank to stack B.
void	push_specific(t_st_list **stacka, t_st_list **stackb, int rank)
{
	t_st_list	*current;
	int			i;
	int			counter;

	counter = 0;
	i = ft_lstsize(*stacka);
	current = *stacka;
	while (current->rank != rank)
	{
		current = current->next;
		counter++;
	}
	current = *stacka;
	while ((*stacka)->rank != rank)
	{
		if (counter > i / 2)
		{
			r_rotate(stacka, 'a');
		}
		else
			rotate(stacka, 'a');
	}
	push(stacka, stackb, 'b');
	return ;
}

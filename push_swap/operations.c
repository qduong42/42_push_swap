/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:35:15 by qduong            #+#    #+#             */
/*   Updated: 2022/04/09 19:02:30 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// if ((*stack1)->next->next) denotes more than 2 numbers -> argc = 3;

void	swap(pst_list **stack, char i)
{
	pst_list	*temp;

	if ((*stack)-> next == 0 || !stack)
		return ;
	temp = (*stack)->next;
	if ((*stack)->next->next)
		(*stack)->next = (*stack)->next->next;
	else
		(*stack)->next = NULL;
	(*stack)->previous = temp;
	temp->next = (*stack);
	temp->previous = NULL;
	(*stack) = temp;
	if (i == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

//sets temp as top of stack

void	rotate(pst_list **stack, char i)
{
	pst_list	*last;
	pst_list	*temp;

	temp = (*stack);
	last = ft_lstlast(*stack);
	(*stack)->next->previous = NULL;
	(*stack) = (*stack)->next;
	last->next = temp;
	temp->previous = last;
	temp->next = NULL;
	if (i == 'a')
		write(1, "ra\n", 3);
	else if (i == 'b')
		write(1, "rb\n", 3);
	else
		return ;
}

void	r_rotate(pst_list **stack, char i)
{
	pst_list	*last;
	pst_list	*temp;

	temp = (*stack);
	last = ft_lstlast(*stack);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = (*stack);
	(*stack)->previous = last;
	(*stack) = last;
	if (i == 'a')
		write(1, "rra\n", 4);
	else if (i == 'b')
		write(1, "rrb\n", 4);
	else
		return ;
}

int	push(pst_list **stack1, pst_list **stack2, char a)
{
	int	i;
	int y;

	i = ft_lstsize(*stack2);
	y = ft_lstsize(*stack1);
	if (i == 0)
	{
		(*stack1) = (*stack1)->next;
		*stack2 = (*stack1)->previous;
		(*stack1)->previous = NULL;
		(*stack2)->previous = NULL;
		(*stack2)->next = NULL;
	}
	else if (y == 1)
	{
		(*stack2)->previous = *stack1;
		(*stack1)->next = (*stack2);
		(*stack2) = (*stack1);
		(*stack1) = NULL;
	}
	else
	{
		(*stack1) = (*stack1)->next;
		(*stack2)->previous = (*stack1)->previous;
		(*stack1)->previous->next = (*stack2);
		(*stack1)->previous = NULL;
		(*stack2) = (*stack2)->previous;
	}
	if (a == 'a')
		write(1, "pa\n", 3);
	else if (a == 'b')
		write(1, "pb\n", 3);
	return (1);
}

//function to push a specific rank to stack B.
void	push_specific(pst_list **stacka, pst_list **stackb, int rank)
{
	pst_list	*current;
	int			i;
	int			counter;

	counter = 0;
	i = ft_lstsize(*stacka);
	//printf("List size:%d\n", i);
	current = *stacka;
	while(current->rank != rank)
	{
		current = current->next;
		counter++;
		//printf("Counter:%d\n", counter);
	}
	current = *stacka;
	while((*stacka)->rank != rank)
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

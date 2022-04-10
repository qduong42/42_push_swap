/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_first_last_not_working.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:07:27 by qduong            #+#    #+#             */
/*   Updated: 2022/04/09 23:27:03 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOT WORKING
void	rotate(t_st_list **stack, char i)
{
	t_st_list *last;
	last = ft_lstlast(*stack);
	t_st_list *first;
	first = *stack;
	printf("old Last previous%p\t", last->previous->next);
	(*stack) = last;
	(*stack)->next = first->next;
	(*stack)->previous = NULL;
	//printf("Last prev %p\t", last->previous);
	last->previous->next = first;
	first->previous = last->previous;
	printf("new Last previous%p\t", last->previous->next);
	//first->next->previous = last;
	//printf("Last prev next value%d\t", last->previous->next->value);
	//last->previous->next = first;
	//first->next = NULL;
	//first->previous = last->previous;
	//printf("First prev value%d\t", first->previous->value);
	//printf("Last prev add:%p\t", last->previous);
	//printf("Value of first next prev:%d\t", first->next->previous->value);
	//printf("Last add:%p\t", last);
	//printf("*Stack:%p\t", (*stack));
	if (i == 'a')
	write(1, "ra\n", 3);
	else
	write(1, "rb\n", 3);
}
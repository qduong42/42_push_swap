/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:16:54 by qduong            #+#    #+#             */
/*   Updated: 2022/04/05 22:57:12 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//creates stack a, init top and bottom
	// pst_list *current;
	// current = *stacka;
	// while(current->next!= NULL)
	// {
	// printf("A Before: %d\t", current->value);
	// current = current->next;
	// }
	// printf("A Before: %d\t", current->value);
	// current = *stackb;
	// printf("B Before: %p\t", current);
	// current = *stacka;
	// while(current->next!= NULL)
	// {
	// printf("A After: %d\t", current->value);
	// current = current->next;
	// }
	// printf("A After: %d\t", current->value);
	// current = *stackb;
	// printf("B After: %d\t", current->value);
	// current = current->next;
	// printf("B After: %d\t", current->value);
	// current = current->next;
	// printf("B After: %p\t", current);

void	ft_createstack(char **argv, pst_list** stack)
{
	pst_list	*tmp;
	size_t		i;

	i = 0;
	while (argv[i])
	{
		tmp = ft_lstnew(ft_atoll(argv[i]), 0);
		ft_lstadd_back(stack, tmp);
		i ++;
	}
}

/*return 0 if error, return 1 if normal in general
**numbers = argc -1 = numbers of number inputs
**2 loops ==> outer loop loops through all numbers
**sorts 1 number then 2 then 3 then 4 then 5 then 6 then numbers */

int	*ft_index_sort(int *array, int numbers)
{
	int	current_number_of_values;
	int	times;
	int	temp;

	times = 0;
	current_number_of_values = 0;
	while (current_number_of_values <= numbers)
	{
		times = current_number_of_values - 1;
			while (times > 0)
			{
				if (array[times] < array[times - 1])
				{
					temp = array[times];
					array[times] = array[times - 1];
					array[times - 1] = temp;
				}
				times--;
			}
		current_number_of_values++;
	}
	return (array);
}

/*	Debugging array in function create rank
	//i = 0;
	// while (argc - 1)
	// {
	// printf("%d\n", array[i]);
	// i++;
	// argc--;
	// }
*/

int	*ft_createrank(int argc, char **argv)
{
	int	*array;
	array = ft_calloc(1, sizeof(int) * argc - 1);
	int	i;

	i = -1;
	while(++i != argc - 1)
		array[i] = ft_atoll(argv[i]);
	ft_index_sort(&array[0], argc - 1);
	return (array);
}

void	ft_assign_rank_to_stacka(int max_index, int *array, pst_list **stacka)
{
	int	i;

	i = 0;
	pst_list *current;
	current = *stacka;
	while(current->next != NULL)
	{
		i = 0;
		while (i < max_index)
		{
		if (current->value == array[i])
		{
			current->rank = i;
		}
		current = current->next;
		i++;
		}
	}
}
// if ((*stacka)->next->next) denotes more than 2 numbers -> argc = 3;
void	swap(pst_list **stack , char i)
{
	pst_list *temp;
	
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
	pst_list *last;
	pst_list *temp;

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
	pst_list *last;
	pst_list *temp;
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

void	rrr(pst_list **stacka, pst_list **stackb)
{
	r_rotate(stacka, 'c');
	r_rotate(stackb, 'c');
	write(1, "rr\n", 3);
	return;
}
void	rr(pst_list **stacka, pst_list **stackb)
{
	rotate(stacka, 'c');
	rotate(stackb, 'c');
	write(1, "rr\n", 3);
	return;
}

int	push(pst_list **stacka, pst_list **stackb, char a)
{
	int i;
	i = ft_lstsize(*stackb);
	if (i == 0)
	{
		(*stacka) = (*stacka)->next;
		*stackb = (*stacka)->previous;
		(*stacka)->previous = NULL;
		(*stackb)->previous = NULL;
		(*stackb)->next = NULL;
	}
	else
	{
		(*stacka) = (*stacka)->next;
		(*stackb)->previous = (*stacka)->previous;
		(*stacka)->previous->next = (*stackb);
		(*stacka)->previous = NULL;
		(*stackb) = (*stackb)->previous;
	}
	if (a == 'a')
		write(1, "pa\n", 3);
	else if (a == 'b')
		write(1, "pb\n", 3);
	return (1);
}

void	sort4(pst_list **stacka, pst_list **stackb)
{
	if ((*stacka)->value == 1)
	{
		push(stacka, stackb, 'b');
		swap(stacka, 'a');
		push(stackb, stacka, 'a');
	}
	return;
}

int	ft_push_swap(int argc, char **argv)
{
	pst_list **stacka;
	pst_list **stackb;
	int *array;

	stacka = ft_calloc(1, sizeof(pst_list*));
	stackb = ft_calloc(1, sizeof(pst_list*));
	if (!stacka || !stackb)
		return(0);
	ft_createstack(argv, stacka);
	array = ft_createrank(argc, argv);
	ft_assign_rank_to_stacka(argc - 2, array, stacka);
	if (argc == 4)
		sort4(stacka, stackb);
	return (1);
}

// only works for argc == 4 
//void	swap_a(pst_list **stacka)
// {
// 	pst_list *first;
// 	pst_list *second;
// 	first = *stacka;
// 	second = *stacka;
// 	second = second->next;
// 	first->next = second->next;
// 	second = first->previous;
// 	second->next->previous = first;
// 	second->next = first;
// 	second->previous = NULL;
// }

int main(int argc, char **argv)
{
	if (argc < 2)
		return(0);
	if(!check_digit(argv))
		return (ft_put_error());
	if(!check_int(argv))
		return(ft_put_error());
	if(!check_duplicates(argv))
		return(ft_put_error());
	if(check_sorted(argc, argv))
		return(0);
	if(!ft_push_swap(argc, &argv[1]))
		return(ft_put_error());
	return(0);
}

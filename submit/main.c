/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:16:54 by qduong            #+#    #+#             */
/*   Updated: 2022/04/10 13:00:10 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//creates stack a, init top and bottom
	// t_st_list *current;
	// current = *stacka;
	// while(current->next!= NULL)
	// {
	// printf("A Before: %d\t", current->value);
	// current = current->next;
	// }
	// printf("A Before: %d\t", current->value);
	// printf("A before: %p\t", current->next);
	// current = *stackb;
	// printf("B Before: %p\t", current);
	// push(stacka, stackb, 'b');
	// push(stacka, stackb, 'b');
	// push(stacka, stackb, 'b');
	// rrr(stacka, stackb);
	// current = *stacka;
	// while(current->next!= NULL)
	// {
	// printf("A After: %d\t", current->value);
	// current = current->next;
	// }
	// printf("A After: %d\t", current->value);
	// printf("A After: %p\t", current->next);
	// current = *stackb;
	// while(current->next!= NULL)
	// {
	// printf("B After: %d\t", current->value);
	// current = current->next;
	// }
	// printf("B After: %d\t", current->value);
	// printf("B After: %p\t", current->next);

// only works for argc == 4 
	//void	swap_a(t_st_list **stacka)
	// {
	// 	t_st_list *first;
	// 	t_st_list *second;
	// 	first = *stacka;
	// 	second = *stacka;
	// 	second = second->next;
	// 	first->next = second->next;
	// 	second = first->previous;
	// 	second->next->previous = first;
	// 	second->next = first;
	// 	second->previous = NULL;
	// }

void	ft_createstack(char **argv, t_st_list **stack)
{
	t_st_list	*tmp;
	size_t		i;

	i = 0;
	while (argv[i])
	{
		tmp = ft_lstnew(ft_atoll(argv[i]), 0);
		ft_lstadd_back(stack, tmp);
		i ++;
	}
	return ;
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

void	ft_createrank(int argc, char **argv, t_st_list **stacka)
{
	int			*array;
	int			i;
	t_st_list	*current;

	current = *stacka;
	array = ft_calloc(1, sizeof(int) * argc - 1);
	i = -1;
	while (++i != argc - 1)
		array[i] = ft_atoll(argv[i]);
	ft_index_sort(&array[0], argc - 1);
	while (current)
	{
		i = 0;
		while ((current)->value != array[i])
			i++;
		(current)->rank = i;
		(current) = (current)->next;
	}
	free(array);
	return ;
}

int	ft_push_swap(int argc, char **argv)
{
	t_st_list	**stacka;
	t_st_list	**stackb;

	stacka = ft_calloc (1, sizeof (t_st_list *));
	stackb = ft_calloc (1, sizeof (t_st_list *));
	if (!stacka || !stackb)
		return (0);
	ft_createstack(argv, stacka);
	ft_createrank(argc, argv, stacka);
	if (argc == 3)
		swap(stacka, 'a');
	if (argc == 4)
		sort3(stacka);
	else if (argc == 5)
		sort4(stacka, stackb);
	else if (argc == 6)
		sort5(stacka, stackb);
	else if (argc >= 6)
		radix(stacka, stackb);
	ft_lstclear(stacka);
	free(stackb);
	free(stacka);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!check_digit(argv))
		return (ft_put_error());
	if (!check_int(argv))
		return (ft_put_error());
	if (!check_duplicates(argv))
		return (ft_put_error());
	if (check_sorted(argc, argv))
		return (0);
	if (!ft_push_swap(argc, &argv[1]))
		return (ft_put_error());
	return (0);
}

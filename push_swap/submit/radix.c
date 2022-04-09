/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:41:13 by qduong            #+#    #+#             */
/*   Updated: 2022/04/09 23:41:58 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//500 = 111110100

static int	get_bit_length(t_st_list **stacka)
{
	int	counter;
	int	i;

	counter = 0;
	i = ft_lstsize(*stacka) - 1;
	while ((i != 0))
	{
	i >>= 1;
	counter++;
	}
	return (counter);
}

void	radix(t_st_list **stacka, t_st_list **stackb)
{
	int	bit_length;
	int	counter;
	int	z;

	counter = 0;
	bit_length = get_bit_length(stacka);
	while (counter < bit_length)
	{
		z = ft_lstsize(*stacka);
		while (z)
		{
			if (((*stacka)->rank >> counter) & 1)
				rotate(stacka, 'a');
			else
				push(stacka, stackb, 'b');
			z--;
		}
		while (*stackb)
			push(stackb, stacka, 'a');
		counter++;
	}
	return ;
}

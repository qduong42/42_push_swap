/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:38:04 by qduong            #+#    #+#             */
/*   Updated: 2022/04/12 10:37:49 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_st_list **stacka, t_st_list **stackb)
{
	r_rotate(stacka, 'c');
	r_rotate(stackb, 'c');
	write(1, "rrr\n", 3);
	return ;
}

void	rr(t_st_list **stacka, t_st_list **stackb)
{
	rotate(stacka, 'c');
	rotate(stackb, 'c');
	write(1, "rr\n", 3);
	return ;
}

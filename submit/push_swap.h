/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:57:34 by qduong            #+#    #+#             */
/*   Updated: 2022/04/09 23:41:50 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct t_ps_list
{
	int					value;
	int					rank;
	struct t_ps_list	*next;
	struct t_ps_list	*previous;
}			t_st_list;

t_st_list	*ft_lstnew(int value, int rank);

t_st_list	*ft_lstlast(t_st_list *lst);

int			ft_lstsize(t_st_list *lst);

void		ft_lstadd_back(t_st_list **lst, t_st_list *new);

void		ft_lstclear(t_st_list **lst);

int			check_digit(char **argv);

int			check_int(char **argv);

int			check_duplicates(char **argv);

int			check_sorted(int argc, char **argv);

int			check_stack_if_sorted(t_st_list **stacka);

void		swap(t_st_list **stack, char i);

void		rotate(t_st_list **stack, char i);

void		r_rotate(t_st_list **stack, char i);

void		rrr(t_st_list **stacka, t_st_list **stackb);

void		rr(t_st_list **stacka, t_st_list **stackb);

int			push(t_st_list **stacka, t_st_list **stackb, char a);

void		sort3(t_st_list **stack);

void		sort5(t_st_list **stacka, t_st_list **stackb);

void		sort4(t_st_list **stacka, t_st_list **stackb);

void		push_specific(t_st_list **stacka, t_st_list **stackb, int rank);

void		radix(t_st_list **stacka, t_st_list **stackb);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:16:54 by qduong            #+#    #+#             */
/*   Updated: 2022/01/07 15:37:44 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//return 0 if error, return 1 if normal in general

int	ft_push_swap(int argc, char **argv)
{
	t_list **stack a;
	t_list **stack b;
	return 1;
}

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
	if(!ft_push_swap(argc, &argv[1]))
		return(ft_put_error());
	return(0);
}

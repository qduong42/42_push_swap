/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:01:54 by qduong            #+#    #+#             */
/*   Updated: 2022/04/05 16:46:52 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Function character to integer, check and skips first occurences of** 
**isspaces. Then check if first character is negative or positive, to**
**multiply with final result*/

long long	ft_atoll(const char *str)
{
	int			i;
	int			is_neg;
	long long	res;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		||str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	else
		is_neg = 1;
	if (is_neg == -1 || str[i] == '+')
		i++;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}	
	return (res * is_neg);
}

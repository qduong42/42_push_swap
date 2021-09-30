/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:55:04 by qduong            #+#    #+#             */
/*   Updated: 2021/06/05 17:43:06 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy (void *dest, const void *src, size_t n)
{
	char	*ldest;
	char	*lsrc;
	size_t	i;

	lsrc = (char *) src;
	ldest = (char *) dest;
	i = 0;
	while (i < n)
	{
		ldest[i] = lsrc[i];
		i++;
	}
	return (dest);
}

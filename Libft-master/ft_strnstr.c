/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:37:11 by qduong            #+#    #+#             */
/*   Updated: 2021/08/18 16:17:13 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

		/*if (n < k || n == 0 || l != k)
		return (NULL);43 to 44 
		refactored additional counter l to j and j to count
		conditions if strlen(little) > n covered by line 40
		original segfaults with NULL pointer and this does too
		For test case uneven needle it fails*/
char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	count;
	size_t	k;

	k = ft_strlen(little);
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < n && big[i] != '\0')
	{
		count = 0;
		while (big[i + count] == little[count] && i + count < n)
		{
			count++;
			if (count == k)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

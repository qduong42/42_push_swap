/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:21:22 by qduong            #+#    #+#             */
/*   Updated: 2021/09/29 16:21:24 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*a;
	size_t	i;

	a = (char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}

int	ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstring)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2[j] != '\n')
	{
		newstring[i++] = s2[j];
		j++;
	}
	if (s2[j] == '\n')
		newstring[i++] = s2[j];
	newstring[i] = '\0';
	return (newstring);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	{
		while (n)
		{
			d[i] = s[i];
			i++;
			n--;
		}
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:39:40 by qduong            #+#    #+#             */
/*   Updated: 2021/08/24 16:00:19 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	tlen;

	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1)
	{
		s1++;
	}
	tlen = ft_strlen(s1);
	while (ft_strchr(set, s1[tlen - 1]) && *s1)
		tlen--;
	trim = ft_substr(s1, 0, tlen);
	return (trim);
}

int    main()
{

char    *s1;
char    *set;
int i;
i = 0;

s1 = "";
set = "test";
char * output;
output = ft_strtrim(s1, set);
while (output[i]!= '\0')
{
	if(output[i] =='\0')
	{printf("%c\n", output[i]);
	break ;}
	printf("%c\n", output[i]);
i++;
}
// printf("%p", s1);
return (0);
}
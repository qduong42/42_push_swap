/* function to check for if buf contains newline, 
** how much to copy as denoted by index and
** how much to copy as denoted by index and
** also to split buf into return and leftover
*/

static char*	ft_bufnchecksplit(char *returnline, char *buf)
{
	int		index;
	char	*temp;
	int		len;

	index = ft_strrchr (buf, '\n');
	if (index != 0)
	{
		temp = ft_strjoin(returnline, buf);
		free (returnline);
		returnline = temp;
		while (buf[len])
			len++;
		ft_memmove(buf, buf + index, len - index);
		ft_bzero(buf + len - index, 1);
	}
	return(returnline);
}

static char*	ft_bufjoin(char *returnline, char *buf)
{
	char *temp;
	temp = ft_strjoin(returnline, buf);
	free (returnline);
	returnline = temp;
	ft_bzero(buf, BUFFER_SIZE);
	return (returnline);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:45:19 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/30 15:15:19 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"

void
	ft_decal(char *s, ssize_t n)
{
	ssize_t	i;
	ssize_t	len;

	n++;
	i = 0;
	len = ft_skip(s, '\0');
	if (n > len)
		s[0] = 0;
	else
	{	
		while (i <= len - n)
		{
			s[i] = s[i + n];
			i++;
		}
	}
	return ;
}

char
	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;
	ssize_t		skip;

	line = ft_strdup("", 0);
	if (!line)
		return (0);
	while (1)
	{
		if (buff[0] == 0)
		{
			if (!(read(fd, buff, BUFFER_SIZE)))
			{
				free(line);
				return (0);
			}
		}
		line = ft_strjoin(line, buff);
		if (!line)
			return (0);
		ft_decal(buff, ft_skip(buff, '\n'));
		skip = ft_skip(line, '\n');
		if (line[skip] == '\n')
		{
			line = ft_strsub(line, skip + 1);
			break ;
		}
	}	
	return (line);
}

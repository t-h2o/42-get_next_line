/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:45:19 by tgrivel           #+#    #+#             */
/*   Updated: 2021/12/06 12:28:25 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char
	*gnl_decal(char *s, ssize_t n)
{
	ssize_t	i;
	ssize_t	len;

	n++;
	i = 0;
	len = gnl_skip(s, '\0');
	if (n >= len)
	{
		len = BUFFER_SIZE + 1;
		while (len--)
			s[len] = 0;
	}
	else
	{	
		while (i <= len - n)
		{
			s[i] = s[i + n];
			i++;
		}
	}
	return (0);
}

char
	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		n;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) != 0))
		return (0);
	line = 0;
	while (1)
	{
		if (buff[0] == 0)
		{
			n = read(fd, buff, BUFFER_SIZE);
			if (!n && !line)
				return (gnl_decal(buff, BUFFER_SIZE - 1));
			if (!n)
				return (line);
		}
		line = gnl_strjoin(line, buff);
		if (!line)
			return (0);
		gnl_decal(buff, gnl_skip(buff, '\n'));
		if (line[gnl_skip(line, '\n')] == '\n')
			return (gnl_strsub(line, gnl_skip(line, '\n')));
	}	
}

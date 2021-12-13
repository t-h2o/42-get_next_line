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
	*gnl_decal(char *s)
{
	ssize_t	i;
	ssize_t	n;

	i = 0;
	n = gnl_skip(s, '\n');
	while (i <= BUFFER_SIZE - n)
	{
		s[i] = s[i + n + 1];
		i++;
	}
	while (i <= BUFFER_SIZE + 1)
		s[i++] = 0;
	return (0);
}
/*		BS	= 5 (buff = 6)
 *
 *		in	:	xNabc0	
 *		out	:	abc000
 *
 *		in	:	abcNx0	
 *		out	:	x00000
 *
 *		in	:	abcde0	
 *		out	:	000000
 */

char
	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) != 0))
		return (0);
	line = 0;
	while (1)
	{
		if (buff[0] == 0)
		{
			if (!(read(fd, buff, BUFFER_SIZE)))
			{
				if (!line)
					return (0);
				else
					return (line);
			}
		}
		line = gnl_strjoin(line, buff);
		if (!line)
			return (0);
		if (line[gnl_skip(line, '\n')] == '\n')
			return (gnl_strsub(line));
	}	
}

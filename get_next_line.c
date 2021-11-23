#include	"./get_next_line.h"

void
	ft_decal(char *s, ssize_t n)
{
	ssize_t	i;
	ssize_t	len;

	i = 0;
	len = ft_strlen(s);
	while (len-- > n)
	{
		s[i] = s[i + n];
		i++;
	}
	while (n--)
	{
		s[i++] = 0;
	}
	return ;
}

char
	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;
	ssize_t		skip;
	ssize_t		n;

	int			endline = 0;
	
	if (buff[0] == 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		line = ft_strjoin("", buff);
	}
	else
		line = ft_strjoin("", buff);

	
	while (!endline)
	{
		skip = 0;
		if (buff[0] == 0)
		{
			n = read(fd, buff, BUFFER_SIZE);
			line = ft_strjoin(line, buff);
		}
			
		while (line[skip] && line[skip] != '\n')
			skip++;
		if (line[skip] == '\n')
		{
			endline = 1;
			line = ft_strsub(line, skip + 1);	
			if (!line)
				return (0);
		}
		examine(buff, "buff");	
		ft_decal(buff, skip + 1);
	}
	
	return (line);
}

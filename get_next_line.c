#include	"./get_next_line.h"
#include	<string.h>
#define		BUFF		examine(buff, "buff");

void
	ft_decal(char *s, ssize_t n)
{
	ssize_t	i;
	ssize_t	len;

	n++;
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

static ssize_t
	ft_skip(char *s)
{
	ssize_t	skip;

	skip = 0;
	while (s[skip] && s[skip] != '\n')
		skip++;
	return (skip);
}

char
	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;
	ssize_t		skip;
	ssize_t		n;
	int			endline;
	
	n = 0;
	endline = 0;	
	line = ft_strdup("", 0);	
	while (!endline)
	{
		if (buff[0] == 0)
		{
			n = read(fd, buff, BUFFER_SIZE);
			if (!n)
			{
				free(line);
				return (0);
			}
		}
		line = ft_strjoin(line, buff);
		skip = ft_skip(line);
		if (line[skip] == '\n')
		{
			endline = 1;
			line = ft_strsub(line, skip + 1);
		}
		skip = ft_skip(buff);
		ft_decal(buff, skip);
	}	
	return (line);
}

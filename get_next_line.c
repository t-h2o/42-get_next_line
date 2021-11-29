#include	"./get_next_line.h"
#include	<string.h>

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

	int			endline = 0;
	
	line = ft_strdup("", 0);	
	while (!endline)
	{
		if (buff[0] == 0)
		{
			read(fd, buff, BUFFER_SIZE);
			line = ft_strjoin(line, buff);
		}
		else
		{	
			line = ft_strjoin(line, buff);
		}
		skip = ft_skip(line);
		printf("\n\tskip line : %.2ld", skip);
		if (line[skip] == '\n')
		{
			endline = 1;
			if (skip + 1 != ft_strlen(line))
				line = ft_strsub(line, skip + 1);
		}
		skip = ft_skip(buff);
		printf("\tskip buff: %.2ld\n", skip);
		ft_decal(buff, skip);
	}	
	return (line);
}

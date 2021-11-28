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

	int			endline = 0;
	
	while (!endline)
	{
		if (buff[0] == 0)
		{
			printf("\nThe buffer is empty\n");
			read(fd, buff, BUFFER_SIZE);
			line = ft_strjoin("", buff);
		}
		else
		{	
			printf("\nthere is '%s' in the buffer\n", buff);
			line = ft_strjoin("", buff);
		}
		skip = 0;
		while (line[skip])
		{
			if (line[skip] == '\n')
			{
				endline = 1;
				break ;
			}
			skip++;
		}
	}	

	return (line);
}

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
	printf("len %ld : decal %ld\n", len, n);
	examine(s, "avatn");
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
	examine(s, "Decal");	
	return ;
}
/*
 * 	SKIPsaCommence
 *	skip = 4
 * 	saCommence
 */

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
	int			endline;
	
	int	cmp = 0;

	endline = 0;	
	line = ft_strdup("", 0);	
	while (!endline)
	{
		if (buff[0] == 0)
		{
			printf("\n\tREAD\n");
			if (!(read(fd, buff, BUFFER_SIZE)))
			{
				free(line);
				return (0);
			}
		}
		if (!line || !(line = ft_strjoin(line, buff)))
			return (0);
		skip = ft_skip(line);
		if (line[skip] == '\n')
		{
			endline = 1;
			line = ft_strsub(line, skip + 1);
		}
		ft_decal(buff, ft_skip(buff));
		printf("\n%.3d | %s", cmp, line);
		cmp++;
	}	
	return (line);
}

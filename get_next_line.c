#include	"./get_next_line.h"

#define BUFF_TEST	examine(buff, "buff");
#define LINE_TEST	examine(line, "line");
#define REST_TEST	examine(rest, "rest");

/*
#define BUFF_TEST	printf("buff :\n%s\n", buff); examine(buff, "buff");
#define LINE_TEST	printf("line :\n%s\n", line); examine(line, "line");
#define REST_TEST	printf("rest :\n%s\n", rest); examine(rest, "rest");
*/

#define ALL_TEST LINE_TEST REST_TEST BUFF_TEST

static int
	ft_finish(char *s)
{
	ssize_t	i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char
	*get_next_line(int fd)
{
	static int	endfile = 0;
	static char	*rest = 0;
	char		*line;
	char		*buff;
	int			endli;

	if (endfile)
		return (0);
	endli = 0;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	buff[BUFFER_SIZE] = 0;

	line = ft_strdup("", 0);
	if (!line)
		return (0);

//	ALL_TEST

	while(!endli && !endfile)
	{
		if (rest)
		{
			line = ft_strjoin(line, rest);
			free(rest);
			rest = 0;
		}
		else
		{
			if (BUFFER_SIZE > read(fd, buff, BUFFER_SIZE))
				endfile = 1;
			if (buff[0] == 0)
			{
				endfile = 1;
				endli = 1;
			}
			line = ft_strjoin(line, buff);
		}
		endli = ft_finish(line);

//		LINE_TEST	
	}
	ssize_t	skip;
	skip = 0;
	while (line[skip] && line[skip] != '\n')
		skip++;
	rest = ft_strdup(line, skip + 1);
	line = ft_strsub(line, skip + 1);

//	BUFF_TEST

	free(buff);
	printf("line [0] : %.3i ", line[0]);
	if (line[0] == 0)
		return (0);
	return (line);
}

#include	"./get_next_line.h"

void
	examine(char *s, char *d)
{
	if (!s)
		return ;
	printf("\n");
	int	i = -1;
	while (s[++i])
	{
		if (s[i] == 10)
			printf("%s s[%.2i] :\t%s\t%i\n", d, i, "\\n", s[i]);	
		else
			printf("%s s[%.2i] :\t%c\t%i\n", d, i, s[i], s[i]);	
	}
	printf("%s s[%.2i] :\t%s\t%i\n", d, i, "\\0", s[i]);	
}

void
	test(int i)
{
	int		fd;
	char	*s;

	fd = open("./README.md", O_RDONLY);
	
	printf("\n[START TEST]\nFD = %.2d\t calls = %.2d\tBS = %d\n\n", fd, i, BUFFER_SIZE);
	int p = i;
	while (i--)
	{
		s = get_next_line(fd);
		if (s)
			printf("%p | %.3i | %s", s, p - i, s);
		else
			printf("%.3i | %s\n", p - i, "EOF");
//		examine(s, "[RETUR]");
		free(s);
		s = 0;
	}
	printf("\n\n[end test]\n");
	close(fd);
}

int
	main()
{
	test(69);
	return (0);
}

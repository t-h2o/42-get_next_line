#include	"./get_next_line.h"
#include	<stdio.h>
#include	<time.h>

static void
	ft_halfseconde(int ms)
{
/*	clock_t	t;

	ms *= 1000;

	t = clock();
	while (clock() - t < ms) {}
*/	(void) ms;		
}

int
	main()
{
	int		fd;
	char	*s;

	fd = open("./file", O_RDONLY);

	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		ft_halfseconde(500);
	}
	
	printf("\n");
	close(fd);

	return (0);
}

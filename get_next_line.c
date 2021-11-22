#include	"./get_next_line.h"
#include	<stdio.h>	

char
	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	read_nb;

	if (!fd || BUFFER_SIZE < 1)
		return (0);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	read_nb = read(fd, buffer, 0);
	printf("nb %ld et \nbuffer : %s\n", read_nb, buffer);
	return (0);

}

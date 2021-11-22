#ifndef	GET_NEXT_LINE_H

# define	GET_NEXT_LINE_H
# include	<unistd.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>

	#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 42
	#endif /* BUFFER_SIZE */

char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */

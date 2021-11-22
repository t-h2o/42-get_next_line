#ifndef	GET_NEXT_LINE_H

# define	GET_NEXT_LINE_H
# include	<unistd.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>

# include	<stdio.h>
void	examine(char *s, char *d);

	#ifndef BUFFER_SIZE
	# define BUFFER_SIZE 4
	#endif /* BUFFER_SIZE */

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
ssize_t	ft_strlen(char *s);
char	*ft_strdup(char *s, ssize_t n);
char	*ft_strsub(char *s, ssize_t n);
#endif /* GET_NEXT_LINE_H */

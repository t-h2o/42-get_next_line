#include	<stdio.h>
#include	<stdlib.h>
#define		LOOP	5

static size_t
	ft_strlen(char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char
	*ft_strdup_char(char *s, char c)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(len + 2);

	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
//		printf("dup[%.2ld] : %c, src[%.2ld] : %c len total %ld\n", i, dup[i], i, s[i], len);
		i++;
	}
	dup[i] = c;
//		printf("dup[%.2ld] : %c, src[%.2ld] : %c len total %ld\n", i, dup[i], i, s[i], len);
	dup[++i] = 0;
	
//	printf("\nsource\t: %s\ndestination\t: %s\n", s, dup);
	return (dup);
}

static char
	*ft_strdup(char *s)
{
	size_t	len;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(len + 1);
	dup[len] = 0;
	while (len--)
		dup[len] = s[len];
//	printf("\nsource\t: %s\ndestination\t: %s\n", s, dup);
	return (dup);
}

void
	ft_strmem(void)
{
	static char c = '1';
	static char *s = 0;
	char		*temp;
	size_t		len;

	if (!s)
	{
		s = ft_strdup("start alpha:");
	}
	temp = ft_strdup(s);
	free(s);
	s = ft_strdup_char(temp, c++);
	printf("\t\nString is : %s\n", s);
}

void
	ft_print_x(void)
{
	static int	x = 4;

	x++;
	printf("\nX value is %d", x);
}

int
	main(void)
{
	int	i;

	i = LOOP;
	ft_print_x();
	while (i--)
		ft_strmem();
	return (0);
}

#include	"./get_next_line.h"

char
	*ft_strsub(char *s, ssize_t n)
{
	char	*r;
	r = (char *)malloc(n + 1);
	if (!r)
		return (0);
	r[n] = 0;
	while (n--)
		r[n] = s[n];
	free(s);
	return (r);
}

char
	*ft_strjoin(char *s1, char *s2)
{
	ssize_t	len;
	ssize_t	i;
	char	*r;

	len = 0;

	printf("s1 : %s\ns2 : %s\n", s1, s2);

	len += ft_strlen(s1);
	len += ft_strlen(s2);
	r = (char *)malloc(len + 1);
	if (!r)
		return (0);
	i = 0;
	len = 0;
	while (s1[i])
		r[len++] = s1[i++];
	i = 0;
	while (s2[i])
		r[len++] = s2[i++];
	free(s1);
	return (r);	
}

ssize_t
	ft_strlen(char *s)
{
	ssize_t	r;
	if (!s)
		return (0);
	r = 0;
	while(s[r])
		r++;
	return (r);
}

char
	*ft_strdup(char *s, ssize_t n)
{
	char	*r;
	ssize_t	i;

	i = ft_strlen(s) - n;
	r = (char *)malloc(i + 1);
	if (!r)
		return (0);
	r[i] = 0;
	while (i--)
		r[i] = s[i + n];
	return (r);
}

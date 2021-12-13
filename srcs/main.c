/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:56:52 by tgrivel           #+#    #+#             */
/*   Updated: 2021/12/06 12:22:12 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"

void
	examine_buffer(char *s, char *d)
{
	int	i;

	i = -1;
	if (!s)
		return ;
	while (i++ < BUFFER_SIZE)
	{
		if (s[i] == 10)
			printf("%s s[%.2i] :\t%s\t%i\n", d, i, "\\n", s[i]);
		else if (s[i] == 0)
			printf("%s s[%.2i] :\t%s\t%i\n", d, i, "\\0", s[i]);
		else
			printf("%s s[%.2i] :\t%c\t%i\n", d, i, s[i], s[i]);
	}
}

void
	examine(char *s, char *d)
{
	int	i;

	i = -1;
	if (!s)
		return ;
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
	test(int i, char *file)
{
	int		fd;
	char	*s;
	int		p;

	p = i;
	fd = open(file, O_RDONLY);
	printf("\n[START TEST]\tbuffer size is %d char\n\n", BUFFER_SIZE);
	while (i--)
	{
		s = get_next_line(fd);
		if (s)
		{
			printf("---%.3i  %s", p - i, s);
			free(s);
		}
		else
		{
			printf("MAIN | %.3i | %s\n", p - i, "EOF");
			i = 0;
		}
	}
	printf("\n[end test]\n");
	close(fd);
}

int
	main(void)
{
	test(34, "./Files/file5");
	test(34, "./Files/file2");
	test(34, "./Files/file3");
	test(34, "./Files/file2");
	return (0);
}

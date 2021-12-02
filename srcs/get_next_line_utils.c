/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:43:05 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/30 15:46:12 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./get_next_line.h"

ssize_t
	gnl_skip(char *s, char c)
{
	ssize_t	n;

	if (!s)
		return (0);
	n = 0;
	while (s[n] && s[n] != c)
		n++;
	return (n);
}

char
	*gnl_strsub(char *s, ssize_t n)
{
	char	*r;

	n++;
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
	*gnl_strjoin(char *s1, char *s2)
{
	ssize_t	len;
	ssize_t	i;
	char	*r;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	if (!s1)
		return (0);
	len = gnl_skip(s1, '\0') + gnl_skip(s2, '\0');
	r = (char *)malloc(len + 1);
	r[len] = 0;
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

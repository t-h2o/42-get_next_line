/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:43:05 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/30 15:15:02 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	len += ft_skip(s1, '\0');
	len += ft_skip(s2, '\0');
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

ssize_t
	ft_skip(char *s, char c)
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
	*ft_strdup(char *s, ssize_t n)
{
	char	*r;
	ssize_t	i;

	i = ft_skip(s, '\0') - n;
	r = (char *)malloc(i + 1);
	if (!r)
		return (0);
	r[i] = 0;
	while (i--)
		r[i] = s[i + n];
	return (r);
}

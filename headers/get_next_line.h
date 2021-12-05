/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:25:11 by tgrivel           #+#    #+#             */
/*   Updated: 2021/11/30 15:37:10 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

	//	include

# include	<unistd.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<stdio.h>

	//	main

void	examine(char *s, char *d);

	//	get-next-line

char	*gnl_decal(char *s, ssize_t n);
char	*get_next_line(int fd);

	//	get_next_line-utils

char	*gnl_strsub(char *s, ssize_t n);
char	*gnl_strjoin(char *s1, char *s2);
ssize_t	gnl_skip(char *s, char c);

#endif /* GET_NEXT_LINE_H */
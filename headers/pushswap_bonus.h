/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:09:53 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/06 10:17:13 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char	*get_next_line(int fd);
char	*ft_get_leftovers(char *buf, int *remember);
char	*ft_get_line(char *line, char *buf, int *remember, int has_read);
char	*ft_check_line(int *remember, char *line);
int		ft_check_remember(int remember);
int		ft_strlen(char *str);
char	*ft_strdup(char *src, int *remember);
int		ft_strchr(char *s, char c);
char	*ft_realloc_and_concat(char *str, size_t oldsize, size_t newsize,
			char *newstr);
char	*ft_free(char *str);

#endif
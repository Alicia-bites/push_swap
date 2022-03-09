/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:16:36 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/04 09:47:44 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# define INVALID_PILE -2
# define EMPTY_STR -3

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_stack
{
	int					elt;
	int					size;
	struct s_lined_up	*prev;
	struct s_lined_up	*next;
}	t_stack;

int			ft_strlen(const char *s);
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void    	ft_lstrip(char *s);
void    	ft_rstrip(char *s);
int			ft_isspace(int c);
void		ft_putchar(char c);
void		ft_putstr(char *s, int isend);
void		ft_putnbr(int n);
int			pile_isvalid(char *s);
int			ft_panic(int errcode);
int			ft_parse(char *arg);
int			ft_isdigit(int c);

#endif
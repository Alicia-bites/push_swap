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
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_lined_up
{
	int					bit;
	pid_t				pid;
	int					srv_flag;
	struct s_lined_up	*prev;
	struct s_lined_up	*next;
}	t_lined_up;

typedef struct s_client
{
	char		*msg;
	size_t		msg_len;
	pid_t		srv_pid;
	uint8_t		flags;
	int			bits_sent;
}	t_client;

enum e_client_flags
{
	MSG_R=1,
	PONG_OK=2,
	CHAR_SENT=3	
};

int			ft_strlen(const char *s);
int			ft_atoi(const char *str);
void		ft_putchar(char c);
void		ft_putstr(char *s, int isend);
void		ft_putnbr(int n);
int			pile_is_valid(char *s);
int			ft_panic(int errcode);
int			ft_isdigit(int c);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:37:28 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/14 15:36:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_putstr(char *s, int isend, int fd)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++, fd);
	if (isend >= 1)
		ft_putchar('\n', fd);
}

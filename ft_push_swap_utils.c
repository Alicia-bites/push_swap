/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:53:08 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/07 14:53:12 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_panic(int errcode)
{
	if (errcode == 1)
		ft_putstr("Usage : ./push_swap <pile>", 1);
	// else if (errcode == )
	// 	ft_putstr("", 1);
	// else if (errcode == )
	// 	ft_putstr("", 1);
	// else if (errcode == )
	// 	ft_putstr("Empty string.", 1);
	// else if (errcode == )
	// 	ft_putstr("", 1);
	return (errcode);
}

//check if pile is valid
int	pile_is_valid(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (1);
}

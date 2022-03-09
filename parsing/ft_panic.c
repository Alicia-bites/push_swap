/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_panic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:07:43 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/09 16:08:36 by amarchan         ###   ########.fr       */
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
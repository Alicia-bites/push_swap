/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:55:23 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/12 18:58:36 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include "../headers/pushswap_bonus.h"

void	ft_error(t_stack *a, t_stack *b, char **moove)
{
	free(*moove);
	ft_clear(a);
	ft_clear(b);
	exit(ft_panic(INVALID_ARG));
}

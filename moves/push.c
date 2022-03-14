/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:08:07 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/14 18:42:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

//push the first elt of b at the top of a
void	ft_pa(t_stack **a, t_stack **b)
{
	if (b)
	{
		ft_lstadd_front(a, *b);
		ft_putstr("pa", 1, 1);		
	}
}

//push the first elt of a at the top of b
void	ft_pb(t_stack **b, t_stack **a)
{
	if (b)
	{
		ft_lstadd_front(b, *a);
		ft_putstr("pb", 1, 1);
	}
}
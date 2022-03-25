/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:56:29 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/18 18:36:49 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_rra(t_stack *stack)
{
	int tmp;

	if (stack)
	{
		while(stack->next)
			stack = stack->next;
		tmp = stack->num;
		while (stack->prev)
		{
			stack->num = stack->prev->num;
			stack = stack->prev;
		}
		stack->num = tmp;
	}
	ft_putstr("rra", 1, 1);
}

void	ft_rrb(t_stack *stack)
{
	int tmp;

	if (stack)
	{
		while(stack->next)
			stack = stack->next;
		tmp = stack->num;
		while (stack->prev)
		{
			stack->num = stack->prev->num;
			stack = stack->prev;
		}
		stack->num = tmp;
	}
	ft_putstr("rrb", 1, 1);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
	ft_putstr("rrr", 1, 1);
}
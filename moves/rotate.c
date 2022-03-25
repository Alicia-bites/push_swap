/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:12:18 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/23 17:22:26 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_ra(t_stack *stack)
{
	int tmp;

	if (stack)
	{
		tmp = stack->num;
		while (stack->next)
		{
			stack->num = stack->next->num;
			stack = stack->next;
		}
		stack->num = tmp;
		stack->next = NULL; 
	}
	ft_putstr("ra", 1, 1);
}

void	ft_rb(t_stack *stack)
{
	int tmp;

	if (stack)
	{
		tmp = stack->num;
		while (stack->next)
		{
			stack->num = stack->next->num;
			stack = stack->next;
		}
		stack->num = tmp;
		stack->next = NULL; 
	}
	ft_putstr("rb", 1, 1);
}

void ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a);
	ft_rb(b);
	ft_putstr("rr", 1, 1);
}

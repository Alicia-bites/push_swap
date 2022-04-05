/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:12:18 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/05 10:37:20 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_ra(t_stack *stack, int i)
{
	int tmp;
	int	tmp_s;

	if (stack)
	{
		tmp = stack->num;
		tmp_s = stack->sorted;
		while (stack->next)
		{
			stack->num = stack->next->num;
			stack->sorted = stack->next->sorted;
			stack = stack->next;
		}
		stack->num = tmp;
		stack->sorted = tmp_s;
		stack->next = NULL; 
	}
	if (i == 0)
		ft_putstr("ra", 1, 1);
}

void	ft_rb(t_stack *stack, int i)
{
	int tmp;
	int	tmp_s;

	if (stack)
	{
		tmp = stack->num;
		tmp_s = stack->sorted;
		while (stack->next)
		{
			stack->num = stack->next->num;
			stack->sorted = stack->next->sorted;
			stack = stack->next;
		}
		stack->num = tmp;
		stack->sorted = tmp_s;
		stack->next = NULL; 
	}
	if (i == 0)
		ft_putstr("rb", 1, 1);
}

void ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	ft_putstr("rr", 1, 1);
}

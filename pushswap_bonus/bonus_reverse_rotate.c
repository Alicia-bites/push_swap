/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:21:11 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/07 18:19:12 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include "../headers/pushswap_bonus.h"

void	ft_rra(t_stack *stack, int i)
{
	int	tmp;
	int	tmp_s;

	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		tmp = stack->num;
		tmp_s = stack->sorted;
		while (stack->prev)
		{
			stack->num = stack->prev->num;
			stack->sorted = stack->prev->sorted;
			stack = stack->prev;
		}
		stack->num = tmp;
		stack->sorted = tmp_s;
	}
	if (i == 0)
		ft_putstr("rra", 1, 1);
}

void	ft_rrb(t_stack *stack, int i)
{
	int	tmp;
	int	tmp_s;

	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		tmp = stack->num;
		tmp_s = stack->sorted;
		while (stack->prev)
		{
			stack->num = stack->prev->num;
			stack->sorted = stack->prev->sorted;
			stack = stack->prev;
		}
		stack->num = tmp;
		stack->sorted = tmp_s;
	}
	if (i == 0)
		ft_putstr("rrb", 1, 1);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a, 1);
	ft_rrb(b, 1);
}

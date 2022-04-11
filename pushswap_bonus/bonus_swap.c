/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:20:55 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/11 16:49:24 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include "../headers/pushswap_bonus.h"

void	ft_sa(t_stack *stack)
{
	int	tmp;
	int	tmp_s;

	if (stack)
	{
		tmp = stack->num;
		tmp_s = stack->sorted;
		stack->num = stack->next->num;
		stack->sorted = stack->next->sorted;
		stack->next->num = tmp;
		stack->next->sorted = tmp_s;
	}
}

void	ft_sb(t_stack *stack)
{
	int	tmp;
	int	tmp_s;

	if (stack)
	{
		tmp = stack->num;
		tmp_s = stack->sorted;
		stack->num = stack->next->num;
		stack->sorted = stack->next->sorted;
		stack->next->num = tmp;
		stack->next->sorted = tmp_s;
	}
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sb(b);
	ft_putstr("ss", 1, 1);
}

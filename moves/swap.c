/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:45:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/15 11:53:22 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

//swap the first 2 elts of the stack
void	ft_sa(t_stack *stack)
{
	int tmp;

	if (stack)
	{
		tmp = stack->num;
		stack->num = stack->next->num;
		stack->next->num = tmp;
		
		ft_putstr("sa", 1, 1);
		ft_putstr("sb", 1, 1);
	}
	
}

void	ft_sb(t_stack *stack)
{
	int tmp;

	if (stack)
	{
		tmp = stack->num;
		stack->num = stack->next->num;
		stack->next->num = tmp;
		ft_putstr("sb", 1, 2);
	}
	
}

void ft_swap_a_and_b(t_stack *a, t_stack *b)
{
	ft_sa(a);
	ft_sb(b);
	ft_putstr("ss", 1, 1);
}
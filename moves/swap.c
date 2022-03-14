/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:45:26 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/14 18:44:27 by amarchan         ###   ########.fr       */
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
		ft_putstr("sa", 1, 2);
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
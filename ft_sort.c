/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:19:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/15 14:19:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	sort_1_3(t_stack *stack)
{
	while (!sort_checka(stack))
	{
		if (stack->ab[stack->atop] > stack->ab[stack->size - 1])
		{
			if (stack->ab[stack->atop] > stack->ab[stack->atop + 1])
				ra(stack, 1, 1);
			else
				rra(stack, 1, 1);
		}
		else
			sa(stack, 1, 1);
	}
}

void	sort_insert(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size / 2)
	{
		if (stack->ab[stack->atop] < stack->size / 2)
		{
			pb(stack, 1, 1);
			i++;
		}
		else
			ra(stack, 1, 1);
	}	
	while (stack->atop < stack->size - 3)
	{
		pb(stack, 1, 1);
		i++;
	}	
	sort_1_3(stack);
	while (i-- >= 0)
		insert(stack);
}

void	sort_1_6(t_stack *stack)
{
	if (!sort_check(stack))
	{
		sort_insert(stack);
		tour_1(stack, 0);
	}
}
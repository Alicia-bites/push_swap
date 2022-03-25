/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:40:12 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/25 14:41:12 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	insert_elt(int idx_a, int idx_b, t_stack **a, t_stack **b)
{
	while (idx_a > 0)
	{
		ft_ra(*a);
		idx_a--;
	}
	while (idx_a < 0)
	{
		ft_rra(*a);
		idx_a++;
	}
	while (idx_b > 0)
	{
		ft_rb(*b);
		idx_b--;
	}
	while (idx_b < 0)
	{
		ft_rrb(*b);
		idx_b++;
	}
}

void	rotate_ab(int idx_a, int idx_b, t_stack **a, t_stack **b)
{
	while (idx_a > 0 && idx_b > 0)
	{
		ft_rr(*a, *b);
		idx_a--;
		idx_b--;
	}
	while (idx_a < 0 && idx_b < 0)
	{
		ft_rrr(*a, *b);
		idx_a++;
		idx_b++;
	}
	insert_elt(idx_a, idx_b, a, b);
}
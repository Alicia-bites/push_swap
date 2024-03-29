/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:40:12 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/05 14:27:44 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	insert_elt(int idx_a, int idx_b, t_stack **a, t_stack **b)
{
	while (idx_a > 0)
	{
		ft_ra(*a, 0);
		idx_a--;
	}
	while (idx_a < 0)
	{
		ft_rra(*a, 0);
		idx_a++;
	}
	while (idx_b > 0)
	{
		ft_rb(*b, 0);
		idx_b--;
	}
	while (idx_b < 0)
	{
		ft_rrb(*b, 0);
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

int	absolu(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	get_last_elt(t_stack *lst)
{
	t_stack	*iterator;

	iterator = lst;
	while (iterator->next)
		iterator = iterator->next;
	return (iterator->sorted);
}

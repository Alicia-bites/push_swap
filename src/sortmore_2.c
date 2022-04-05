/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:37:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/05 16:00:17 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_revlst(t_stack **lst)
{
	while ((*lst)->next)
		*lst = (*lst)->next;
}

static int	getindex(t_stack *a, t_stack *b)
{
	t_stack	*it_a;

	it_a = a;
	if (b->sorted > a->sorted)
	{
		while (it_a->next && b->sorted > it_a->sorted)
		{
			it_a = it_a->next;
			if (it_a && it_a->sorted < it_a->prev->sorted)
				return (it_a->index);
		}
	}
	else
	{
		ft_revlst(&it_a);
		while (b->sorted < it_a->sorted && it_a->prev)
		{
			if (it_a && it_a->prev->sorted > it_a->sorted)
				return (it_a->index);
			it_a = it_a->prev;
		}
	}
	if (it_a->sorted < b->sorted)
		return (it_a->index + 1);
	return (it_a->index);
}

static int	ft_count_moves(int index_a, int index_b)
{
	if (index_a * index_b >= 0)
	{
		if (absolu(index_a) > absolu(index_b))
			return (absolu(index_a));
		else
			return (absolu(index_b));
	}
	if (index_a * index_b < 0)
		return (absolu(index_a - index_b));
	return (0);
}

static void	ft_check_insert(t_sort *stacks, int *pos, int idx_a, int idx_b)
{
	int	moves;

	moves = -1;
	if (idx_a > ft_lstsize(stacks->a) / 2)
		idx_a = idx_a - (ft_lstsize(stacks->a));
	if (idx_b > ft_lstsize(stacks->b) / 2 && ft_lstsize(stacks->b) > 2)
		idx_b = idx_b - ft_lstsize(stacks->b);
	moves = ft_count_moves(idx_a, idx_b);
	if ((moves >= 0 && moves < pos[2]) || idx_b == 0)
	{
		pos[0] = idx_a;
		pos[1] = idx_b;
		pos[2] = moves;
	}
}

//place b elt at the right place in a.
void	insert(t_stack **a, t_stack **b)
{
	int		mem[3];
	int		idx_a;
	int		idx_b;
	t_stack	*it_b;
	t_sort	stacks;

	it_b = (*b);
	mem[0] = 0;
	mem[1] = 0;
	mem[2] = -1;
	stacks.a = *a;
	stacks.b = *b;
	while (it_b)
	{
		idx_b = it_b->index;
		idx_a = getindex(*a, it_b);
		ft_check_insert(&stacks, mem, idx_a, idx_b);
		if (mem[2] == 0 || mem[2] == 1)
			break ;
		it_b = it_b->next;
	}
	rotate_ab(mem[0], mem[1], a, b);
	ft_pa(a, b);
}

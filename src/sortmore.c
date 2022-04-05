/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:44:48 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/05 15:34:31 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

static int	get_a_index(t_stack *a)
{
	t_stack	*iterator;
	int		index_a;

	iterator = a;
	while (iterator->next)
	{
		if (iterator->sorted > iterator->next->sorted)
			index_a = iterator->next->index;
		iterator = iterator->next;
	}
	return (index_a);
}

//sort the a stack
static void	sort_a(t_stack **a)
{
	int		index_a;

	index_a = get_a_index(*a);
	if (index_a < ft_lstsize(*a) / 2)
	{
		while (index_a > 0)
		{
			ft_ra(*a, 0);
			index_a--;
		}
	}
	else
	{
		index_a = ft_lstsize(*a) - index_a;
		while (index_a > 0)
		{
			ft_rra(*a, 0);
			index_a--;
		}
	}
}

//push the first half of stack a in stack b,
//then push the stack a leftovers in stack b until there's only 3 elts left in a
static void	sort_insert(t_stack **a)
{
	int		i;
	t_stack	*b;

	i = 0;
	b = NULL;
	while (i < ((*a)->size / 2))
	{
		if ((*a)->sorted < ((*a)->size / 2))
		{
			ft_pb(&b, a);
			i++;
		}
		else
			ft_ra(*a, 0);
	}
	while (i < (*a)->size - 3)
	{
		ft_pb(&b, a);
		i++;
	}
	sort_3(*a);
	while (i-- > 0)
		insert(a, &b);
}

void	sort_more(t_stack **a)
{
	if (!is_sorted(*a))
	{
		sort_insert(a);
		sort_a(a);
	}
}

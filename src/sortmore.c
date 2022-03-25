/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:44:48 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/25 14:52:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

//sort the a stack
static void	sort_a(t_stack **a)
{
	t_stack *iterator;
	int	index_a;

	iterator = *a;
	while (iterator->next)
	{
		if (iterator->num > iterator->next->num)
			index_a = iterator->next->index;
		iterator = iterator->next;
	}
	if (index_a < ft_lstsize(*a) / 2)
	{
		while (index_a > 0)
		{
			ft_ra(*a);
			index_a--;
		}
	}
	else
	{
		index_a = ft_lstsize(*a) - index_a;
		while (index_a > 0)
		{
			ft_rra(*a);
			index_a--;
		}
	}
}

// check if b elt can be placed at the right place in a in one move
// if not, remember for the b elt what moves need to be done
// by stocking them in a tab
static void	insert(t_stack **a, t_stack **b)
{
	int	moves;
	int index_b;
	t_stack *it_a;
	t_stack *it_b;
	//t_stack *iterator;
	it_b = (*b);
	while (it_b)
	{
		moves = 0;
		it_a = (*a);
		while (it_a && (it_b->num > it_a->num))
		{
			printf("B NUM : %d\n", it_b->num);
			printf("A NUM : %d\n", it_a->num);
			moves++;
			it_a = it_a->next;
		}
		printf("moves : %d\n", moves);
		if (moves > (ft_lstsize(*a) / 2))
			moves = moves - ft_lstsize(*a);
		if (moves == 0 || moves == 1)
			break ;
		index_b = it_b->index;
		it_b = it_b->next;
	}
	printf("moves : %d\n", moves);
	printf("idx_a : %d\n", moves);
	printf("idx_b : %d\n", index_b);
	rotate_ab(moves, index_b, a, b);
	ft_pa(a, b);
	// iterator = *a;
	// while (iterator)
	// {
	// 	printf("iterator->num = %d\n", iterator->num);
	// 	// if (iterator->prev)
	// 		// printf("iterator->prev->num = %d\n", iterator->prev->num);
	// 	iterator = iterator->next;
	// 	//printf("iterator->prev->num = %d\n", iterator->index);
	// }
}

//push the first half of stack a in stack b,
//then push the stack a leftovers in stack b until there's only 3 elts left in a
static void	sort_insert(t_stack **a)
{
	int	i;
	t_stack	*b;
	//t_stack *b_it;
	//t_stack *a_it;

	i = 0;
	b = NULL;
	while (i < ((*a)->size / 2))
	{
		printf("(*a)->size : %d\n", (*a)->size);
		printf("(*a)->sorted : %d\n", (*a)->sorted);
		if ((*a)->sorted > ((*a)->size / 2))
		{
			ft_pb(&b, a);
			i++;
		}
		else
			ft_ra(*a);
	}
	while (i < (*a)->size - 3)
	{
		ft_pb(&b, a);
		i++;
	}
	// b_it = b;
	// while (b_it)
	// {
	// 	printf("b_it->num = %d\n", b_it->num);
	// 	//printf("b_it->index = %d\n", b_it->index);
	// 	// if (b_it->next)
	// 	// 	printf("b_it->num = %d\n", b_it->next->num);
	// 	b_it = b_it->next;
	// }
	// printf("i : %d\n", i);
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
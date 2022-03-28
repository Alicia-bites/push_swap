/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:44:48 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/28 12:20:01 by amarchan         ###   ########.fr       */
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
		if (iterator->sorted > iterator->next->sorted)
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
	int	index_a;
	int index_b;
	t_stack *it_a;
	t_stack *it_b;
	t_stack *iterator;
	it_b = (*b);
	while (it_b)
	{
		index_b = it_b->index;
		moves = 0;
		it_a = (*a);
		while (it_a && (it_b->sorted > it_a->sorted))
		{
			moves++;
			index_a = it_a->index;
			it_a = it_a->next;
		}
		//printf("moves : %d\n", moves);
		if (moves > (ft_lstsize(*a) / 2))
			moves = moves - ft_lstsize(*a);
		// if (moves == 0 && it_b->sorted !=)
		//printf("moves : %d\n", moves);
		if (moves == 0 || moves == 1)
			break ;
		it_b = it_b->next;
	}
	//printf("moves : %d\n", moves);
	//("idx_a : %d\n", moves);
	//printf("idx_b : %d\n", index_b);
	rotate_ab(moves, index_b, a, b);
	ft_pa(a, b);
	// if ((*a)->sorted > (*a)->next->sorted)
	// 	ft_ra(*a);
}

//push the first half of stack a in stack b,
//then push the stack a leftovers in stack b until there's only 3 elts left in a
static void	sort_insert(t_stack **a)
{
	int	i;
	t_stack	*b;
	t_stack *b_it;
	t_stack *a_it;

	i = 0;
	b = NULL;
	while (i < ((*a)->size / 2))
	{
		//printf("sorted : %d\n",(*a)->sorted);
		if ((*a)->sorted < ((*a)->size / 2))
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
	// 	//printf("a_it->index = %d\n", a_it->index);
	// 	// if (a_it->next)
	// 	// 	printf("a_it->num = %d\n", a_it->next->num);
	// 	b_it = b_it->next;
	// }
	//puts("-----------------------------------------------");
	sort_3(*a);
	// a_it = *a;
	// while (a_it)
	// {
	// 	printf("a_it->num = %d\n", a_it->num);
	// 	//printf("b_it->index = %d\n", b_it->index);
	// 	// if (b_it->next)
	// 	// 	printf("b_it->num = %d\n", b_it->next->num);
	// 	a_it = a_it->next;
	// }
	while (i-- > 0)
	{
		insert(a, &b);
		sort_a(a);
	}
	// a_it = *a;
	// while (a_it)
	// {
	// 	printf("a_it->num = %d\n", a_it->num);
	// 	//printf("b_it->index = %d\n", b_it->index);
	// 	// if (b_it->next)
	// 	// 	printf("b_it->num = %d\n", b_it->next->num);
	// 	a_it = a_it->next;
	// }
}

void	sort_more(t_stack **a)
{
	if (!is_sorted(*a))
	{
		sort_insert(a);
		sort_a(a);
	}
}
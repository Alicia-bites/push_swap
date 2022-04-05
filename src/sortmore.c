/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortmore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:44:48 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/05 14:05:28 by amarchan         ###   ########.fr       */
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

int	get_last_elt(t_stack *lst)
{
	t_stack	*iterator;

	iterator = lst;
	while (iterator->next)
		iterator = iterator->next;
	return (iterator->sorted);
}

int	getindex(t_stack *a, t_stack *b)
{
	t_stack	*it_a;
	int	idx_a;

	// printf("a->sorted in getindex : %d\n", a->sorted);
	// printf("b->sorted in getindex : %d\n", b->sorted);
	if (b->sorted > a->sorted)
	{
		it_a = a;
		while (it_a->next && b->sorted > it_a->sorted)
		{
			it_a = it_a->next;
			if (it_a && it_a->sorted < it_a->prev->sorted)
					return (it_a->index);
		}
	}
	else
	{
		it_a = a;
		while (it_a->next)
			it_a = it_a->next;
		while (b->sorted < it_a->sorted && it_a->prev)
		{
			if (it_a && it_a->prev->sorted > it_a->sorted)
					return (it_a->index);				
			it_a = it_a->prev;
		}
	}
	//printf("index a = %d\n", it_a->index);
	if (it_a->sorted < b->sorted)
		return (it_a->index + 1);
	//printf("index a = %d\n", it_a->index);
	return (it_a->index);
}

int	absolu(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_count_moves(int index_a, int index_b)
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

void	ft_check_insert()
{
	
}
// check if b elt can be placed at the right place in a in one move
// if not, remember for the b elt what moves need to be done
// by stocking them in a tab
// index_a = where I wanna put the be elt in a.
static void	insert(t_stack **a, t_stack **b)
{
	int	moves;
	int pos[3];
	int	idx_a;
	int idx_b;
	t_stack *it_a;
	t_stack *it_b;
	t_stack *iterator;

	it_b = (*b);
	pos[2] = -1;
	pos[0] = 0;
	pos[1] = 0;
	while (it_b)
	{
		idx_b = it_b->index;
		moves = 0;
		idx_a = getindex(*a, it_b);
		if (idx_a > ft_lstsize(*a) / 2)
			idx_a = idx_a - (ft_lstsize(*a));
		if (idx_b > ft_lstsize(*b) / 2 && ft_lstsize(*b) > 2)
			idx_b = idx_b - ft_lstsize(*b);
		// printf("idx_a = %d\n", idx_a);
		// printf("idx_b = %d\n" , idx_b);
		moves = ft_count_moves(idx_a, idx_b);
		// printf("moves = %d\n", moves);
		// puts("---------------------------------------------------");
		if ((moves >= 0 && moves < pos[2]) || idx_b == 0)
		{
			pos[0] = idx_a;
			pos[1] = idx_b;
			pos[2] = moves;	
		}
		if (pos[2] == 0 || pos[2] == 1)
			break ;
		it_b = it_b->next;
	}
	//printf("first_idx_b = %d\n", idx_b);
	if (idx_b >= ft_lstsize(*b) / 2 && ft_lstsize(*b) > 2)
		idx_b = idx_b - ft_lstsize(*b);
	// printf("pos : %d\n", moves);
	// printf("idx_a = %d\n", idx_a);
	// printf("idx_b : %d\n", idx_b);
	// printf("pos[0] (a) : %d\n", pos[0]);
	// printf("pos[1] (b) : %d\n", pos[1]);
	rotate_ab(pos[0], pos[1], a, b);
	ft_pa(a, b);
	// it_b = *b;
	// while (it_b)
	// {
	// 	printf("b = %d\n", it_b->sorted);
	// 	//printf("a_it->sorted = %d\n", it_a->sorted);
	// 	// if (b_it->next)
	// 	// 	printf("b_it->num = %d\n", b_it->next->num);
	// 	it_b = it_b->next;
	// }
	// puts("---------------------------------------------------");
	// it_a = *a;
	// while (it_a)
	// {
	// 	printf("a = %d\n", it_a->sorted);
	// 	//printf("a_it->index = %d\n", it_a->index);
	// 	// if (b_it->next)
	// 	// 	printf("b_it->num = %d\n", b_it->next->num);
	// 	it_a = it_a->next;
	// }
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
		//printf("(*a)->size / 2 = %d\n" , (*a)->size / 2);
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
		//printf("(*a)->sorted : %d\n", (*a)->sorted);
		ft_pb(&b, a);
		i++;
	}
	// b_it = b;
	// while (b_it)
	// {
	// 	printf("b_it->sorted = %d\n", b_it->sorted);
	// 	//printf("a_it->index = %d\n", a_it->index);
	// 	// if (a_it->next)
	// 	// 	printf("a_it->num = %d\n", a_it->next->num);
	// 	b_it = b_it->next;
	// }
	// puts("-----------------------------------------------");
	sort_3(*a);
	// a_it = *a;
	// while (a_it)
	// {
	// 	printf("a_it->sorted = %d\n", a_it->sorted);
	// 	//printf("a_it->index = %d\n", a_it->index);
	// 	// if (b_it->next)
	// 	// 	printf("b_it->num = %d\n", b_it->next->num);
	// 	a_it = a_it->next;
	// }
	while (i-- > 0)
		insert(a, &b);
	// a_it = *a;
	// while (a_it)
	// {
	// 	printf("a_it->sorted = %d\n", a_it->sorted);
	// 	//printf("b_it->index = %d\n", b_it->index);
	// 	// if (b_it->next)
	// 	// 	printf("b_it->num = %d\n", b_it->next->num);
	// 	a_it = a_it->next;
	// }
}

void	sort_more(t_stack **a)
{
	t_stack	*a_it;
	if (!is_sorted(*a))
	{
		sort_insert(a);
		sort_a(a);
	}
	// a_it = *a;
	// while (a_it)
	// {
	// 	printf("a_it->sorted = %d\n", a_it->sorted);
	// 	//printf("b_it->index = %d\n", b_it->index);
	// 	// if (b_it->next)
	// 	// 	printf("b_it->num = %d\n", b_it->next->num);
	// 	a_it = a_it->next;
	// }
}
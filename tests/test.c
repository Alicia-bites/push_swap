#include "../headers/ft_push_swap.h"

void	sort_3(t_stack *stack)
{
	t_stack *last_elt;

	last_elt = stack;
	while (last_elt->next)
		last_elt = last_elt->next;
	while (!is_sorted(stack))
	{
		if (stack->num > last_elt->num)
		{
			if (stack->num > stack->next->num)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else
			ft_sa(stack);
	}
}

// check if b elt can be placed at the right place in a in one move
// if not, remember for the b elt what moves need to be done
// by stocking them in a tab
void	insert(t_stack **a, t_stack **b)
{
	int	moves;
	int index_b;
	t_stack *it_a;
	t_stack *it_b;
	t_stack *iterator;
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
	iterator = *a;
	while (iterator)
	{
		printf("iterator->num = %d\n", iterator->num);
		// if (iterator->prev)
			// printf("iterator->prev->num = %d\n", iterator->prev->num);
		iterator = iterator->next;
		//printf("iterator->prev->num = %d\n", iterator->index);
	}
}

//sort the a stack
void	sort_a(t_stack **a)
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

//push the first half of stack a in stack b,
//then push the stack a leftovers in stack b until there's only 3 elts left in a
void	sort_insert(t_stack **a)
{
	int	i;
	t_stack	*b;
	t_stack *b_it;
	t_stack *a_it;

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

//create list b and sort stack bigger than 3
void	sort_more(t_stack **a)
{
	if (!is_sorted(*a))
	{
		sort_insert(a);
		sort_a(a);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	t_stack *a;
	t_stack	*copy;
	t_stack *iterator;
	t_stack	*b = NULL;
	i = 1;
	if (argc > 2)
	{
		while (argv[i])
			a = ft_create_list(argc, argv[i++]);
		iterator = a;
		while (iterator)
		{
			printf("iterator->num = %d\n", iterator->num);
			printf("a->sorted = %d\n", iterator->sorted);
			//printf("iterator->next = %p\n", iterator->next);
			// if (iterator->prev)
				// printf("iterator->prev->num = %d\n", iterator->prev->num);
			iterator = iterator->next;
			//printf("iterator->prev->num = %d\n", iterator->index);
		}
		puts("----------------------------------------");
		copy = ft_lstcopy(a);
		init_sort(copy);
		ft_getsorted(&a, copy);
		//ft_pb(&b, &a);
		//ft_rrb(a);
		ft_sb(a);
		//sort_3(a);
		//sort_4(&a);
		puts("----------------------------------------");
		iterator = a;
		while (iterator)
		{
			printf("a->num = %d\n", iterator->num);
	//		if (iterator->prev)
		//		printf("iterator->prev->num = %d\n", iterator->prev->num);
			//printf("a->index = %d\n", iterator->index);
			printf("a->sorted = %d\n", iterator->sorted);
			iterator = iterator->next;
		}
		iterator = b;
		while (iterator)
		{
			printf("a->num = %d\n", iterator->num);
	//		if (iterator->prev)
		//		printf("iterator->prev->num = %d\n", iterator->prev->num);
			//printf("a->index = %d\n", iterator->index);
			printf("b->sorted = %d\n", iterator->sorted);
			iterator = iterator->next;
		}
	}
	return (0);
}
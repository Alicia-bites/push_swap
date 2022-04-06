/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:49:19 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/06 14:31:41 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

//sort a list of max 3 elements
void	sort_3(t_stack *stack)
{
	t_stack	*last_elt;

	last_elt = stack;
	while (last_elt->next)
		last_elt = last_elt->next;
	while (!is_sorted(stack))
	{
		if (stack->num > last_elt->num)
		{
			if (stack->num > stack->next->num)
				ft_ra(stack, 0);
			else
				ft_rra(stack, 0);
		}
		else
			ft_sa(stack);
	}
}

void	ft_print_stack(t_stack *stack)
{
	t_stack	*iterator;

	iterator = stack;
	while (iterator)
	{
		printf("%d\n", iterator->sorted);
		iterator = iterator->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*copy;
	int		i;

	i = 1;
	if (argc <= 2)
		return (0);
	while (argv[i])
		a = ft_parse(argc, argv[i++]);
	copy = ft_lstcopy(a);
	init_sort(copy);
	ft_getsorted(&a, copy);
	if (argc <= 4)
		sort_3(a);
	else
		sort_more(&a);
	ft_clear(copy);
	ft_clear(a);
	return (0);
}

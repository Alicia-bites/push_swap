/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:00:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/06 14:40:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include "../headers/pushswap_bonus.h"

void	ft_do_op(t_stack *a, char *moove)
{
	if (ft_strcmp("sa") == ft_strcmp(moove))
		ft_sa(a);
}

char	*get_instructions(void)
{
	char	*moove;
	
	moove = get_next_line(0);
	return (moove);
}

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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*copy;
	int		i;
	char	*moove;

	i = 1;
	if (argc <= 1)
		return (0);
	while (argv[i])
		a = ft_parse(argc, argv[i++]);
	copy = ft_lstcopy(a);
	init_sort(copy);
	ft_getsorted(&a, copy);
	moove = get_instructions();
	ft_do_op(moove);
	if (argc <= 4)
		sort_3(a);
	else
		sort_more(&a);
	ft_clear(copy);
	ft_clear(a);
	return (0);
}

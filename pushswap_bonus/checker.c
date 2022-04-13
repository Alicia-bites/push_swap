/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:00:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/12 18:58:47 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include "../headers/pushswap_bonus.h"

void	ft_do_op(t_stack **a, t_stack **b, char *moove)
{
	if (ft_strcmp("sa\n", moove) == 0)
		ft_sa(*a);
	else if (ft_strcmp("sb\n", moove) == 0)
		ft_sb(*b);
	else if (ft_strcmp("pa\n", moove) == 0)
		ft_pa(a, b);
	else if (ft_strcmp("pb\n", moove) == 0)
		ft_pb(b, a);
	else if (ft_strcmp("ra\n", moove) == 0)
		ft_ra(*a, 1);
	else if (ft_strcmp("rb\n", moove) == 0)
		ft_rb(*b, 1);
	else if (ft_strcmp("rr\n", moove) == 0)
		ft_rr(*a, *b);
	else if (ft_strcmp("rra\n", moove) == 0)
		ft_rra(*a, 1);
	else if (ft_strcmp("rrb\n", moove) == 0)
		ft_rrb(*b, 1);
	else if (ft_strcmp("rrr\n", moove) == 0)
		ft_rrr(*a, *b);
	else if (ft_strcmp("ss\n", moove) == 0)
		ft_ss(*a, *b);
	else
		ft_error(*a, *b, &moove);
}

char	*get_instructions(void)
{
	char	*moove;

	moove = get_next_line(0);
	return (moove);
}

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

void	check_that_pile(t_stack **a, t_stack **b)
{
	char	*moove;

	moove = "yo";
	while (moove != NULL && *(a) != NULL)
	{
		moove = get_instructions();
		if (!moove)
			break ;
		ft_do_op(a, b, moove);
		free(moove);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	b = NULL;
	i = 1;
	if (argc <= 1)
		return (0);
	while (argv[i])
		a = ft_parse(argc, argv[i++]);
	check_that_pile(&a, &b);
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_clear(a);
	ft_clear(b);
	return (0);
}

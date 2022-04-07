/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:06 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/07 18:18:42 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include "../headers/pushswap_bonus.h"

//reset the index of elts
void	ft_index_reset(t_stack **stack)
{
	int		i;
	t_stack	*iterator;

	iterator = *stack;
	i = 0;
	while ((*stack))
	{
		(*stack)->index = i++;
		(*stack) = (*stack)->next;
	}
	(*stack) = iterator;
}

//push the first elt of b at the top of a
void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*new;
	t_stack	*iterator;
	int		i;

	if (!(*b))
		return ;
	if (!(*a))
		*a = ft_lstnew((*a)->size, (*b)->num, 0, (*b)->sorted);
	else
	{
		new = ft_lstnew((*a)->size, (*b)->num, 0, (*b)->sorted);
		ft_lstadd_front(a, new);
		iterator = *a;
		i = 1;
		while ((*a)->next)
		{
			(*a)->next->index = i++;
			(*a) = (*a)->next;
		}
		(*a) = iterator;
	}
	ft_lstclear_first(b);
	ft_index_reset(b);
}

//push the first elt of a at the top of b
void	ft_pb(t_stack **b, t_stack **a)
{
	t_stack	*new;
	t_stack	*iterator;
	int		i;

	if (!(*a))
		return ;
	if (!(*b))
		*b = ft_lstnew((*a)->size, (*a)->num, 0, (*a)->sorted);
	else
	{
		new = ft_lstnew((*a)->size, (*a)->num, 0, (*a)->sorted);
		ft_lstadd_front(b, new);
		iterator = *b;
		i = 1;
		while ((*b)->next)
		{
			(*b)->next->index = i++;
			(*b) = (*b)->next;
		}
		(*b) = iterator;
	}
	ft_lstclear_first(a);
	ft_index_reset(a);
}

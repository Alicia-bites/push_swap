/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:07:43 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/25 14:53:12 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	ft_panic(int errcode)
{
	if (errcode == MISSING_ARG)
		ft_putstr("Error", 1, 2);
	else if (errcode == EMPTY_STR)
		ft_putstr("Error", 1, 2);
	else if (errcode == FOUND_DUP)
		ft_putstr("Error", 1, 2);
	else if (errcode == NOT_INT)
		ft_putstr("Error", 1, 2);
	else if (errcode == OUT_INT)
		ft_putstr("Error", 1, 2);
	else if (errcode == INVALID_ARG)
		ft_putstr("Error", 1, 2);
	else if (errcode == MALLOC_FAILURE)
		ft_putstr("Error", 1, 2);
	return (errcode);
}

//check if duplicate entry
int	ft_checkdup(t_stack *stack, int elt)
{
	t_stack	*iterator;

	if (stack)
	{
		iterator = stack;
		while (iterator->next)
		{
			if (iterator->num == elt)
			{
				ft_panic(FOUND_DUP);
				exit(EXIT_FAILURE);
			}
			iterator = iterator->next;
		}
	}
	return (0);
}

//sort stack a
t_stack	*init_sort(t_stack *stack)
{
	int		temp;
	t_stack	*sorted_a;

	sorted_a = stack;
	while (!(is_sorted(sorted_a)))
	{
		while (sorted_a->next)
		{
			if (sorted_a->num > sorted_a->next->num)
			{
				temp = sorted_a->num;
				sorted_a->num = sorted_a->next->num;
				sorted_a->next->num = temp;
			}
			sorted_a = sorted_a->next;
		}
		while (sorted_a->prev)
			sorted_a = sorted_a->prev;
	}
	return (sorted_a);
}

void	ft_getsorted(t_stack **a, t_stack *copy)
{
	t_stack	*it_a;
	t_stack	*it_copy;

	it_a = *a;
	while (it_a)
	{
		it_copy = copy;
		while (it_copy)
		{
			if (it_a->num == it_copy->num)
			{
				it_a->sorted = it_copy->index;
				break ;
			}
			it_copy = it_copy->next;
		}
		it_a = it_a->next;
	}
}

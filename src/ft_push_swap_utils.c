/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:53:08 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/06 14:31:49 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

//check if list is sorted
//if elt is bigger than next elt, return 0. 
int	is_sorted(t_stack *stack)
{	
	t_stack	*iterator;

	iterator = stack;
	while (iterator->next)
	{
		if (iterator->num > iterator->next->num)
			return (0);
		iterator = iterator->next;
	}
	return (1);
}

void	ft_clear(t_stack *stack)
{
	ft_lstclear(&stack);
	ft_lstclear_back(&stack);
}

int	is_complete(t_stack *a)
{
	t_stack	*iterator;

	iterator = a;
	while (iterator->next)
		iterator = iterator->next;
	if (a->size == (iterator->index + 1))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 17:53:03 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/10 12:23:23 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_lstadd_back(t_stack **first_elt, t_stack *new)
{
	t_stack	*iterator;

	iterator = *first_elt;
	if (first_elt && new)
	{
		if (!*first_elt)
			*first_elt = new;
		else
		{	
			while (iterator->next)
				iterator = iterator->next;
			iterator->next = new;
			new->prev = iterator;
		}
	}
}

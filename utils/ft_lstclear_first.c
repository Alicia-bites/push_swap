/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:28:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/05 19:57:44 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_lstclear_first(t_stack **elt)
{
	t_stack	*iterator;

	if (*elt && elt)
	{
		iterator = *elt;
		*elt = NULL;
		if (iterator->next)
			*elt = iterator->next;
		else
			*elt = NULL;
		if (iterator->next && *elt)
			(*elt)->prev = NULL;
		free(iterator);
	}
}

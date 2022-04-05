/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:28:33 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/23 18:08:43 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_lstclear_first(t_stack **elt)
{
	t_stack	*iterator;

	iterator = *elt;
	free(*elt);
	if (iterator->next)
		*elt = iterator->next;
	else
		*elt = NULL;
	if (iterator->next)
		(*elt)->prev = NULL;
}

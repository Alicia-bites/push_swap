/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:53:40 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/25 13:43:51 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

t_stack	*ft_lstnew(int size, int arg, int index)
{
	t_stack	*elt;

	elt = malloc(sizeof(t_stack));
	if (!elt)
	{
		ft_panic(MALLOC_FAILURE);
		exit(EXIT_FAILURE);
	}
	elt->num = arg;
	elt->index = index;
	elt->sorted = 0;
	elt->size = size;
	elt->prev = NULL;
	elt->next = NULL;
	return (elt);
}

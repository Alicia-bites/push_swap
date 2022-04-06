/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 11:53:40 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/05 18:34:19 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

t_stack	*ft_lstnew(int size, int arg, int index, int sorted)
{
	t_stack	*elt;

	elt = malloc(sizeof(t_stack));
	if (!elt)
	{
		ft_panic(MALLOC_FAILURE);
		free(elt);
		exit(EXIT_FAILURE);
	}
	elt->num = arg;
	elt->index = index;
	elt->sorted = sorted;
	elt->size = size;
	elt->prev = NULL;
	elt->next = NULL;
	return (elt);
}

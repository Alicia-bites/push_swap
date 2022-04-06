/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:01:56 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/06 09:24:17 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

t_stack	*ft_lstcopy(t_stack *lst)
{
	t_stack	*output;
	t_stack	*iterator;
	t_stack	*tmp;

	output = ft_lstnew(lst->size, lst->num, lst->index, lst->sorted);
	iterator = lst;
	iterator = iterator->next;
	while (iterator)
	{
		tmp = iterator;
		tmp = iterator->next;
		tmp = ft_lstnew(iterator->size, iterator->num, iterator->index,
				iterator->sorted);
		ft_lstadd_back(&output, tmp);
		iterator = iterator->next;
	}
	return (output);
}

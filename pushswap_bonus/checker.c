/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:00:41 by amarchan          #+#    #+#             */
/*   Updated: 2022/04/06 10:56:50 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"
#include "../headers/pushswap_bonus.h"



int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*copy;
	int		i;

	i = 1;
	if (argc <= 2)
		return (ft_panic(MISSING_ARG));
	while (argv[i])
		a = ft_parse(argc, argv[i++]);
	copy = ft_lstcopy(a);
	init_sort(copy);
	ft_getsorted(&a, copy);
	if (argc <= 4)
		sort_3(a);
	else
		sort_more(&a);
	ft_print_stack(a);
	ft_clear(copy);
	ft_clear(a);
	return (0);
}
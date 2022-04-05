/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarchan <amarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:52:10 by amarchan          #+#    #+#             */
/*   Updated: 2022/03/09 14:52:47 by amarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;
	size_t		i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dest = (char *)s1;
	src = (const char *)s2;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:14:22 by wbaali            #+#    #+#             */
/*   Updated: 2025/02/06 17:25:46 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*findlast(t_pile *pile)
{
	if (!pile)
		return (NULL);
	while (pile->next)
		pile = pile->next;
	return (pile);
}

t_pile	*findmax(t_pile *pile)
{
	long	max;
	t_pile	*maxnode;

	if (!pile)
		return (NULL);
	max = LONG_MIN;
	while (pile)
	{
		if (pile->nbr > max)
		{
			max = pile->nbr;
			maxnode = pile;
		}
		pile = pile->next;
	}
	return (maxnode);
}

t_pile	*findmin(t_pile *stack)
{
	long	min;
	t_pile	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

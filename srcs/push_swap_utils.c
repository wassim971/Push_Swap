/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:00:43 by wbaali            #+#    #+#             */
/*   Updated: 2025/02/04 11:36:01 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*get_cheapest(t_pile *pile)
{
	if (!pile)
		return (NULL);
	while (pile)
	{
		if (pile->cheap)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}

void	prep_push(t_pile **pile, t_pile *high_node, char pilename)
{
	while (*pile != high_node)
	{
		if (pilename == 'a')
		{
			if (high_node->abovemedian)
				ra(pile, false);
			else
				rra(pile, false);
		}
		else if (pilename == 'b')
		{
			if (high_node->abovemedian)
				rb(pile, false);
			else
				rrb(pile, false);
		}
	}
}

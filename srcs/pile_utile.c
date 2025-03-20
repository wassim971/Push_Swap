/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:02:54 by wbaali            #+#    #+#             */
/*   Updated: 2025/01/24 09:53:42 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_len(t_pile *pile)
{
	int	count;

	if (!pile)
		return (0);
	count = 0;
	while (pile)
	{
		pile = pile->next;
		count++;
	}
	return (count);
}

bool	pile_sorted(t_pile *pile)
{
	if (!pile)
		return (1);
	while (pile->next)
	{
		if (pile->nbr > pile->next->nbr)
			return (false);
		pile = pile->next;
	}
	return (true);
}

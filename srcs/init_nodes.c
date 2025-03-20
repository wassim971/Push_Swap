/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:29:19 by wbaali            #+#    #+#             */
/*   Updated: 2025/01/25 18:08:33 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_pile *pile)
{
	int	i;
	int	median;

	i = 0;
	if (!pile)
		return ;
	median = pile_len(pile) / 2;
	while (pile)
	{
		pile->index = i;
		if (i <= median)
			pile->abovemedian = true;
		else
			pile->abovemedian = false;
		pile = pile->next;
		i++;
	}
}

static void	set_target_a(t_pile *a, t_pile *b)
{
	t_pile	*current_b;
	t_pile	*target_node;
	long	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_index)
			{
				best_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN)
			a->target = findmax(b);
		else
		{
			a->target = target_node;
		}
		a = a->next;
	}
}

static void	cost_analysis_a(t_pile *a, t_pile *b)
{
	int	len_a;
	int	len_b;

	len_a = pile_len(a);
	len_b = pile_len(b);
	while (a)
	{
		a->pushcost = a->index;
		if (!(a->abovemedian))
			a->pushcost = len_a - (a->index);
		if (a->target->abovemedian)
			a->pushcost += a->target->index;
		else
			a->pushcost += len_b - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_pile *pile)
{
	long	valeur_cheap;
	t_pile	*cheapest_node;

	if (!pile)
		return ;
	valeur_cheap = LONG_MAX;
	while (pile)
	{
		if (pile->pushcost < valeur_cheap)
		{
			valeur_cheap = pile->pushcost;
			cheapest_node = pile;
		}
		pile = pile->next;
	}
	cheapest_node->cheap = true;
}

void	init_nodes_a(t_pile *a, t_pile *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

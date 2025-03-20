/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:24:57 by wbaali            #+#    #+#             */
/*   Updated: 2025/02/06 14:04:56 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_pile **pile, int n)
{
	t_pile	*node;
	t_pile	*last_node;

	if (!pile)
		return ;
	node = malloc(sizeof(t_pile));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	node->cheap = 0;
	if (!(*pile))
	{
		*pile = node;
		node->prev = NULL;
	}
	else
	{
		last_node = findlast(*pile);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_pile_a(t_pile **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (check_syntax(av[i]))
		{
			ft_free_split(av);
			free_errors(a);
		}
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_free_split(av);
			free_errors(a);
		}
		if (check_duplicate(*a, (int)n))
		{
			ft_free_split(av);
			free_errors(a);
		}
		append_node(a, (int)n);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbaali <wbaali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:16:25 by wbaali            #+#    #+#             */
/*   Updated: 2025/02/10 19:40:36 by wbaali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

char	*set_tabs(char	*av)
{
	char	*tab;
	size_t	i;
	size_t	j;

	i = ft_strlen(av);
	j = 0;
	tab = malloc(sizeof(char) * i + 1);
	if (!tab)
		return (NULL);
	while (j < i)
	{
		tab[j] = av[j];
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char	**set_tab(char **av, int ac)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * ac);
	if (!tab)
		return (NULL);
	while (i < ac - 1)
	{
		tab[i] = set_tabs(av[i]);
		if (!tab[i])
			return (ft_free_split(tab), NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	sort(t_pile *a, t_pile *b)
{
	if (pile_len(a) == 2)
		sa(&a, false);
	else if (pile_len(a) == 3)
		sort_three(&a);
	else
		sort_pile(&a, &b);
	free_pile(&a);
}

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	char	**tab;

	a = NULL;
	b = NULL;
	tab = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		exit(EXIT_FAILURE);
	else if (ac == 2)
		tab = ft_splits(av[1], ' ');
	else
	{
		tab = set_tab((av + 1), ac);
		if (!tab)
			exit(EXIT_FAILURE);
	}
	init_pile_a(&a, tab);
	ft_free_split(tab);
	if (!pile_sorted(a))
		sort(a, b);
	else
		free_pile(&a);
	return (0);
}

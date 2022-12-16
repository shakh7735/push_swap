/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:30:41 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/08 17:34:42 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_free(t_list **a, t_list **b, int size, int *tab);

int	main(int ac, char **av)
{
	t_list	*b;
	t_list	*a;
	int		*tab;
	int		size;

	if (ac < 2)
	{
		print_er ();
		return (0);
	}
	tab = malloc(sizeof(int) * 5000);
	if (!tab)
		return (0);
	size = chek_argv (ac, av, tab);
	if (size == 0 || chek_tab(tab, size) == 0)
	{
		print_er ();
		return (0);
	}
	tab = ft_index_tab(tab, size);
	a = init_a (tab, size);
	b = NULL;
	sort_free(&a, &b, size, tab);
	return (0);
}

static void	sort_free(t_list **a, t_list **b, int size, int tab[])
{
	if (size <= 5)
		sort_small_f(*a, *b, 1, 1);
	else
		sort_tab(*a, *b, size, tab);
	free_mal(*a, tab);
}

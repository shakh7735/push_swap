/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:07:46 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/07 18:15:24 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_ok(t_list *a, t_list *b, int tab[]);
static void	ft_chek_operation(t_list **a, t_list **b, int tab[]);
static int	instruct_chek(t_list **a, t_list **b, const char *s);

int	main(int ac, char **av)
{
	t_list	*b;
	t_list	*a;
	int		*tab;
	int		size;

	if (ac < 2)
		print_er ();
	tab = malloc(sizeof(int) * 5000);
	if (!tab)
		return (0);
	size = chek_argv (ac, av, tab);
	if (size == 0 || chek_tab(tab, size) == 0)
	{
		free (tab);
		print_er ();
	}
	tab = ft_index_tab(tab, size);
	a = init_a (tab, size);
	b = NULL;
	ft_chek_operation (&a, &b, tab);
	print_ok(a, b, tab);
	return (0);
}

static void	print_ok(t_list *a, t_list *b, int tab[])
{
	if (chek_sort(a) && !b)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_mal(a, tab);
}

static void	ft_chek_operation(t_list **a, t_list **b, int tab[])
{
	char	*oper;

	oper = get_next_line(0);
	while (1 && oper)
	{
		if (!oper || !instruct_chek(a, b, oper))
		{
			free (oper);
			free_mal(*a, tab);
			print_er ();
		}
		oper = get_next_line(0);
	}
}

static int	instruct_chek(t_list **a, t_list **b, const char *s)
{
	if (!ft_strcmp(s, "sa\n"))
		swap_stack (*a);
	else if (!ft_strcmp(s, "sb\n"))
		swap_stack (*b);
	else if (!ft_strcmp(s, "ss\n"))
		double_swap (*a, *b);
	else if (!ft_strcmp(s, "ra\n"))
		rotate_stack (*a);
	else if (!ft_strcmp(s, "ra\n"))
		rotate_stack (*b);
	else if (!ft_strcmp(s, "rr\n"))
		double_rotate (*a, *b);
	else if (!ft_strcmp(s, "rra\n"))
		reverse_rotate (*a);
	else if (!ft_strcmp(s, "rrb\n"))
		reverse_rotate (*b);
	else if (!ft_strcmp(s, "rrr\n"))
		double_rev_rotate (*a, *b);
	else if (!ft_strcmp(s, "pa\n"))
		push_stack (b, a);
	else if (!ft_strcmp(s, "pb\n"))
		push_stack (a, b);
	else
		return (0);
	return (1);
}

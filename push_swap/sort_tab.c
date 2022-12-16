/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:07:08 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/08 18:23:48 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_tab(t_list *a, t_list *b, int size, int *tab)
{
	int	sb;
	int	st2;
	int	st3;

	sb = sort_to_bit(a, b, 1, 0);
	a = init_rep (a, tab, size);
	b = NULL;
	st2 = sort_tab2(a, b, 1, 0);
	a = init_rep (a, tab, size);
	b = NULL;
	st3 = sort_tab3(a, b, 1, 0);
	a = init_rep (a, tab, size);
	b = NULL;
	if (st2 <= sb && st2 <= st3)
		return (sort_tab2(a, b, 1, 1));
	else if (st3 < sb && st3 < st2)
		return (sort_tab3(a, b, 1, 1));
	else
		return (sort_to_bit(a, b, 1, 1));
	return (0);
}

int	sort_tab3(t_list *a, t_list *b, int i, int prin)
{
	int	size;

	size = size_list(a);
	while (!chek_sort(a) || b)
	{
		while (a->next->next && !chek_sort(a))
		{
			if (a->data == min_as_stek(a) && i++)
				instruct (&a, &b, "pb", prin);
			if (a->data > a->next->data && a->data > last_data(a) && i++)
				instruct (&a, &b, "ra", prin);
			else if (a->data > a->next->data && a->data < last_data(a) && i++)
				instruct (&a, &b, "sa", prin);
			else if (a->data < a->next->data && a->data > last_data(a) && i++)
				instruct (&a, &b, "rra", prin);
			else if (a->data != min_as_stek(a))
				i += shift_min(a, b, 1, prin);
		}
		while (b && i++)
			instruct (&a, &b, "pa", prin);
	}
	return (i -1);
}

int	shift_min(t_list *a, t_list *b, int i, int prin)
{
	int	trend;
	int	size;

	size = size_list(a);
	trend = search_min(a, min_as_stek(a));
	while (a->data != min_as_stek(a) && i++)
	{
		if (a->data > a->next->data)
			instruct (&a, &b, "sa", prin);
		else if (trend < size / 2)
			instruct (&a, &b, "ra", prin);
		else
			instruct (&a, &b, "rra", prin);
	}
	return (i - 1);
}

int	*ft_index_sort(int temp[], int size)
{
	int	i;
	int	min;

	i = -1;
	while (++i < size)
	{
		if (i + 1 < size && temp[i] > temp[i + 1])
		{
			min = temp[i];
			temp[i] = temp[i + 1];
			temp[i + 1] = min;
			i = -1;
		}
	}
	return (temp);
}

int	*ft_index_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	*temp;

	temp = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		temp[i] = (tab)[i];
	i = -1;
	temp = ft_index_sort(temp, size);
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if ((tab)[i] == temp[j])
			{
				(tab)[i] = j;
				break ;
			}
		}
	}
	free (temp);
	return (tab);
}

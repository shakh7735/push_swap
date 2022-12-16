/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:24:43 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/08 18:43:54 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_tab2(t_list *a, t_list *b, int i, int prin)
{
	int	trend;
	int	size;

	size = size_list(a);
	trend = 0;
	while (!chek_sort(a) || b)
	{
		while (a->next && !chek_sort(a))
		{
			trend = search_min(a, min_as_stek(a));
			if (i++ && a->data == min_as_stek(a))
				instruct (&a, &b, "pb", prin);
			else if (trend < size / 2)
				instruct (&a, &b, "ra", prin);
			else
				instruct (&a, &b, "rra", prin);
		}
		while (b && i++)
			instruct (&a, &b, "pa", prin);
	}
	return (i - 1);
}

int	sort_small_t(t_list *a, t_list *b, int i, int size)
{
	if (size == 2)
		if (a->data > a->next->data && i++)
			instruct(&a, &b, "sa", 1);
	while (size == 3 && !chek_sort(a))
	{
		if (a->data > a->next->data && a->data > a->next->next->data \
				&& a->next->data > a->next->next->data && i++)
			instruct(&a, &b, "ra", 1);
		else if (a->data < a->next->data && a->data > a->next->next->data \
				&& a->next->data > a->next->next->data && i++)
			instruct(&a, &b, "rra", 1);
		else if (a->data > a->next->data && a->data < a->next->next->data \
				&& a->next->data > a->next->next->data && i++)
			instruct(&a, &b, "sa", 1);
		else if (a->data < a->next->data && a->data < a->next->next->data \
				&& a->next->data > a->next->next->data && i++)
			instruct(&a, &b, "rra", 1);
		else if (a->data > a->next->data && a->data > a->next->next->data \
				&& a->next->data < a->next->next->data && i++)
			instruct(&a, &b, "ra", 1);
		else if (a->data > a->next->data && a->data < a->next->next->data \
				&& a->next->data < a->next->next->data && i++)
			instruct(&a, &b, "sa", 1);
	}
	return (i -1);
}

int	sort_small_f(t_list *a, t_list *b, int i, int prin)
{
	while (!chek_sort(a) && size_list(a) > 3)
	{
		if ((a->data == min_as_stek(a) || a->data == max_as_stek(a)) && i++)
			instruct(&a, &b, "pb", prin);
		else if ((a->next->data == min_as_stek(a) \
					|| a->next->data == max_as_stek(a)) && i++)
			instruct(&a, &b, "sa", prin);
		else if ((last_data(a) == min_as_stek(a) \
					|| last_data(a) == max_as_stek(a)) && i++)
			instruct(&a, &b, "rra", prin);
		else if (i++)
			instruct(&a, &b, "ra", prin);
	}
	i += sort_small_t(a, b, 1, size_list(a));
	while (!chek_sort(a) || b)
	{
		if (b->data > max_as_stek(a) && i++ && i++)
		{
			instruct(&a, &b, "pa", prin);
			instruct(&a, &b, "ra", prin);
		}
		else if (b->data < min_as_stek(a) && i++)
			instruct(&a, &b, "pa", prin);
	}
	return (i - 1);
}

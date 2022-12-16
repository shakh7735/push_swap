/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:44:23 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/08 18:48:56 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_as_stek(t_list *a)
{
	int	min;

	min = a->data;
	while (a)
	{
		if (a->data < min)
			min = a->data;
		a = a->next;
	}
	return (min);
}

int	max_as_stek(t_list *a)
{
	int	max;

	max = a->data;
	while (a)
	{
		if (a->data > max)
			max = a->data;
		a = a->next;
	}
	return (max);
}

int	last_data(t_list *a)
{
	int	last;

	while (a)
	{
		last = a->data;
		a = a->next;
	}
	return (last);
}

int	search_min(t_list *a, int min)
{
	int	trend;

	trend = 0;
	while (a)
	{
		trend++;
		if (a->data == min)
			break ;
		a = a->next;
	}
	return (trend);
}

int	chek_sort(t_list *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

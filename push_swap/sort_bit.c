/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:00:16 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/08 18:06:14 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chek_bit_b(t_list *b, int rank);
static int	bit_loop(t_list **a, t_list **b, int rank, int prin);

int	sort_to_bit(t_list *a, t_list *b, int i, int prin)
{
	int	rank;
	int	b_size;

	b_size = 1;
	rank = size_list(a);
	while (rank && b_size++)
		rank /= 2;
	rank = -1;
	while (!chek_sort(a) && ++rank < b_size)
		i += bit_loop(&a, &b, rank, prin);
	while (b && i++)
		instruct (&a, &b, "pa", prin);
	return (i - 1);
}

static int	bit_loop(t_list **a, t_list **b, int rank, int prin)
{
	int	i[3];

	i[0] = 1;
	i[1] = exist_to_culc(*a, rank);
	i[2] = 0;
	while (*a)
	{
		if ((*a)->data == i[1])
			i[2]++;
		if (i[2] > 1)
			break ;
		if (i[0]++ && !(((*a)->data >> rank) & 1))
			instruct (a, b, "pb", prin);
		else
			instruct (a, b, "ra", prin);
	}
	while (b)
	{
		if (chek_bit_b(*b, rank) && i[0]++)
			instruct (a, b, "pa", prin);
		else
			break ;
	}
	return (i[0] - 1);
}

static int	chek_bit_b(t_list *b, int rank)
{
	while (b)
	{
		if ((b->data >> (rank + 1)) & 1)
			return (1);
		b = b->next;
	}
	return (0);
}

int	exist_to_culc(t_list *a, int rank)
{
	while (a)
	{
		if (((a->data >> rank) & 1))
			return (a->data);
		a = a->next;
	}
	return (-1);
}

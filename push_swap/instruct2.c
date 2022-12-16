/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:22:09 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/07 18:29:26 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_list **st1, t_list **st2)
{
	t_list	*temp;
	t_list	*temp2;

	if (!*st1)
		return ;
	temp = *st1;
	*st1 = (*st1)->next;
	if (*st2)
	{
		temp2 = *st2;
		*st2 = temp;
		(*st2)->next = temp2;
	}
	else
	{
		*st2 = temp;
		(*st2)->next = NULL;
	}
}

void	swap_stack(t_list *st)
{
	int	temp;

	if (st && st->next)
	{
		temp = st->data;
		st->data = st->next->data;
		st->next->data = temp;
	}
}

void	rotate_stack(t_list *st)
{
	int	tp;

	tp = st->data;
	if (st && st->next)
	{
		while (st)
		{
			if (st->next)
				st->data = st->next->data;
			if (!st->next)
				st->data = tp;
			st = st->next;
		}
	}
}

void	reverse_rotate(t_list *st)
{
	int		temp;
	int		tp;
	t_list	*r;

	r = st;
	if (st && st->next)
	{
		temp = st->data;
		while (st && st->next)
		{
			tp = st->next->data;
			st->next->data = temp;
			temp = tp;
			st = st->next;
		}
		r->data = temp;
	}
}

int	size_list(t_list *lst)
{
	int	size;

	size = 0;
	while (++size && lst)
		lst = lst->next;
	return (size - 1);
}

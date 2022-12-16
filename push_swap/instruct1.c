/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:18:34 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/07 18:21:45 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_list *a, t_list *b)
{
	swap_stack(a);
	swap_stack(b);
}

void	double_rotate(t_list *a, t_list *b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	double_rev_rotate(t_list *a, t_list *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	instruct(t_list **a, t_list **b, const char *s, int prin)
{
	if (!ft_strcmp(s, "sa"))
		swap_stack (*a);
	else if (!ft_strcmp(s, "sb"))
		swap_stack (*b);
	else if (!ft_strcmp(s, "ss"))
		double_swap (*a, *b);
	else if (!ft_strcmp(s, "ra"))
		rotate_stack (*a);
	else if (!ft_strcmp(s, "ra"))
		rotate_stack (*b);
	else if (!ft_strcmp(s, "rr"))
		double_rotate (*a, *b);
	else if (!ft_strcmp(s, "rra"))
		reverse_rotate (*a);
	else if (!ft_strcmp(s, "rrb"))
		reverse_rotate (*b);
	else if (!ft_strcmp(s, "rrr"))
		double_rev_rotate (*a, *b);
	else if (!ft_strcmp(s, "pa"))
		push_stack (b, a);
	else if (!ft_strcmp(s, "pb"))
		push_stack (a, b);
	put_str_prin(s, prin);
}

void	put_str_prin(const char *s, int prin)
{
	if (prin)
	{
		write (1, s, ft_strlen(s));
		write (1, "\n", 1);
	}
}

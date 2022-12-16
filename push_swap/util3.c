/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:53:34 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/08 19:55:40 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_er(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

void	free_mal(t_list *a, int tab[])
{
	t_list	*temp;

	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	free (tab);
}

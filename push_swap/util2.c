/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:19:41 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/08 19:53:19 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	min;
	int	i;
	int	rez;

	rez = 0;
	i = 0;
	min = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -min;
	while (str[i] >= '0' && str[i] <= '9')
		rez = rez * 10 + (str[i++] - 48);
	return (rez * min);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = -1;
	while (s1 && s2 && s1[++i])
		if (s1[i] - s2[i])
			return (s1[i] - s2[i]);
	return (0);
}

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = content;
	new_node->next = NULL;
	return (new_node);
}

t_list	*init_a(int tab[], int size)
{
	t_list	*lst_a;
	t_list	*temp;
	t_list	*first_a;
	int		i;

	temp = ft_lstnew ((tab)[0]);
	first_a = temp;
	i = 0;
	while (++i < size)
	{
		lst_a = ft_lstnew ((tab)[i]);
		temp->next = lst_a;
		temp = temp->next;
	}
	lst_a = NULL;
	temp = NULL;
	return (first_a);
}

t_list	*init_rep(t_list *a, int tab[], int size)
{
	t_list	*first_a;
	int		i;

	first_a = a;
	i = -1;
	while (++i < size)
	{
		a->data = (tab)[i];
		a = a->next;
	}
	return (first_a);
}

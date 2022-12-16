/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:06:39 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/08 19:48:56 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_argv(int ac, char **av, int tab[])
{
	char	*temp;
	int		i;
	int		len;

	len = 0;
	i = 0;
	temp = malloc(sizeof(char) * 12);
	while (++i < ac)
	{
		if (!chek_str(av[i]))
			return (0);
		if (error_num(av[i]))
			return (0);
		len = chek_argv_loop(av[i], tab, len, temp);
	}
	free(temp);
	return (len);
}

int	chek_argv_loop(char *str, int tab[], int index, char *temp)
{
	int		j;
	int		t;

	j = 0;
	while (str[j])
	{
		t = 0;
		while (str[j] == ' ')
			j++;
		if (str[j] == '+' && ++j)
			temp[t++] = '+';
		else if (str[j] == '-' && ++j)
			temp[t++] = '-';
		while (str[j] && str[j] >= '0' && str[j] <= '9')
			temp[t++] = str[j++];
		temp[t] = 0;
		if (t == 12 || !temp || ((temp[0] == '-' || temp[0] == '+') && temp[1] == 0))
			print_er();
		while (str[j] == ' ')
			j++;
		tab[index++] = ft_atoi(temp);
	}
	return (index);
}

int	chek_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && (str[i] == '-' || str[i] == '+' || str[i] == ' ' \
				|| str[i] == '\t' || (str[i] >= '0' && str[i] <= '9')))
		if (str[i + 1] && (str[i] == '-' || str[i] == '+'))
			if (str[i + 1] == ' ' || str[i + 1] == '\t')
				return (0);
	if (str[i])
		return (0);
	return (1);
}

int	chek_tab(int tab[], int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size / 2 + 1)
	{
		j = i;
		while (++j < size)
			if (tab[i] == tab[j])
				return (0);
	}
	return (size);
}

int	error_num(char *str)
{
	int				min;
	int				i;
	long long int	rez;

	rez = 0;
	i = 0;
	min = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -min;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rez = rez * 10 + (str[i++] - 48);
		if (rez * min > INT_MAX || rez * min < INT_MIN)
			return (1);
	}
	return (0);
}

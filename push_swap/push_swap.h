/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshakhge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 18:36:05 by eshakhge          #+#    #+#             */
/*   Updated: 2022/05/07 18:45:42 by eshakhge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

void	free_mal(t_list *a, int tab[]);
void	swap_stack(t_list *st);
void	rotate_stack(t_list *st);
void	reverse_rotate(t_list *st);
void	push_stack(t_list **st1, t_list **st2);
void	double_swap(t_list *a, t_list *b);
void	double_rotate(t_list *a, t_list *b);
void	double_rev_rotate(t_list *a, t_list *b);
void	instruct(t_list **a, t_list **b, const char *s, int prin);

void	print_er(void);
void	put_str_prin(const char *s, int prin);
int		chek_argv(int ac, char **av, int tab[]);
int		chek_str(char *str);
int		chek_tab(int tab[], int size);
t_list	*init_a(int tab[], int size);
t_list	*init_rep(t_list *a, int tab[], int size);
int		chek_sort(t_list *a);
int		error_num(char *str);
int		chek_argv_loop(char *str, int tab[], int index, char *temp);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
size_t	ft_strlen(char const *str);

int		sort_tab(t_list *a, t_list *b, int size, int tab[]);
int		sort_tab2(t_list *a, t_list *b, int i, int prin);
int		sort_tab3(t_list *a, t_list *b, int i, int prin);
int		sort_small_t(t_list *a, t_list *b, int i, int prin);
int		sort_small_f(t_list *a, t_list *b, int i, int prin);

int		size_list(t_list *lst);
int		last_data(t_list *a);
int		min_as_stek(t_list *a);
int		max_as_stek(t_list *a);
int		search_min(t_list *a, int min);
int		shift_min(t_list *a, t_list *b, int i, int prin);

int		sort_to_bit(t_list *a, t_list *b, int i, int prin);
int		*ft_index_tab(int tab[], int size);
int		*ft_index_sort(int temp[], int size);
int		exist_to_culc(t_list *a, int rank);
int		calc_to_size(int ac, char **av);

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# ifndef OPEN_MAX

#  define OPEN_MAX 65535

# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
char	*ft_strjoin_up(char *s1, char const *s2);
int		ft_strchr_n(const char *s, int c);
char	*ft_strtrim_line(char *temp, char const *line);
char	*ft_line_up_to_temp(char *temp);
void	ft_freemalloc(char *s);
char	*ft_strjoin_up_free(char *temp, char *str);
void	ft_bzero(void *str, size_t n);
char	*get_next_line_one(int fd, char *temp);

#endif

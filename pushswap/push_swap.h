/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:28:01 by halaqoh           #+#    #+#             */
/*   Updated: 2022/03/26 10:19:21 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}t_list;

int		sab(t_list *stack_ab, char *operation);
void	pab(t_list **stack_b, t_list **stack_a, char *operation);
void	rab(t_list **stack_ab, char *operation);
void	rrab(t_list **stack_a, char *operation);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content, int index);
t_list	*del_first(t_list *stack);
int		ft_lstsize(t_list *lst);
void	ft_sort3(t_list **stack_a);
int		ft_sort5(t_list **stack_a, t_list **stack_b);
void	ft_nbdup(t_list *lst);
int		ft_min(t_list *stack_a);
int		ft_atoi(char *str);
int		ft_split(char const *s, char c, t_list **stack_a);
void	ft_sort_int_tab(int *tab, int size);
int		ft_min_index(t_list *stack_a);
void	ft_indexsorted(t_list *stack_a, int *tmp);
void	ft_free(t_list *stack_a);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_check(char c, va_list args);
int		ft_printf(const char *str, ...);
int		ft_check_sorted(t_list *stack_a);
int		ft_strncmp(char *s1, char *s2);

#endif
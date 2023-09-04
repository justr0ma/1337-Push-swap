/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:05:30 by halaqoh           #+#    #+#             */
/*   Updated: 2022/03/26 10:24:35 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	signe(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

int	ft_atoi(char *str)
{
	int		inc[3];

	inc[0] = 0;
	inc[1] = 0;
	inc[2] = 0;
	if (ft_strncmp(str, "-2147483648"))
		return (-2147483648);
	if ((str[inc[0]] == '-' || str[inc[0]] == '+') && str[inc[0] + 1] != '\0')
		inc[0]++;
	while (str[inc[0]] >= '0' && str[inc[0]] <= '9')
	{
		inc[1] = (inc[1] * 10) + str[inc[0]++] - '0';
		if (inc[1] < inc[2])
			if (write(2, "Error\n", 7))
				exit (0);
		inc[2] = inc[1];
	}
	if (str[inc[0]] != '\0')
		if (write(2, "Error\n", 7))
			exit (0);
	return (signe(str[0]) * inc[1]);
}

int	ft_min(t_list *stack_a)
{
	int	min;
	int	i;
	int	ii;

	i = 0;
	min = stack_a->content;
	while (stack_a)
	{
		i++;
		if (min >= stack_a->content)
		{
			min = stack_a->content;
			ii = i;
		}
		stack_a = stack_a->next;
	}
	return (ii);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_nbdup(t_list *lst)
{
	t_list	*n;
	int		i;
	int		j;

	i = 0;
	j = ft_lstsize(lst) - 1;
	while (i < j)
	{
		n = lst;
		while (n && n->next)
		{
			if (lst->content == n->next->content)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			n = n->next;
		}
		i++;
		lst = lst->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 19:44:03 by halaqoh           #+#    #+#             */
/*   Updated: 2022/03/20 17:54:51 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_word(const char *s, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i + 1])
				i++;
			a++;
		}
		i++;
	}
	return (a);
}

char	*ft_strndup(char *s, int n)
{
	int		k;
	char	*str;

	k = 0;
	str = malloc(n + 1);
	if (!str)
		return (0);
	while (k < n)
	{
		str[k] = s[k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	**mn_split(char **str, const char *s, const char c)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			str[a] = ft_strndup((char *) s + i, j);
			a++;
			i += j - 1;
		}
		i++;
	}
	str[a] = NULL;
	return (str);
}

int	ft_split(char const *s, char c, t_list **stack_a)
{
	int		nb_word;
	char	**str_split;
	int		i;
	int		j;

	i = 0;
	nb_word = ft_count_word(s, c);
	if (!s || s[0] == '\0' || !nb_word)
	{
		write (2, "Error\n", 6);
		exit (0);
	}
	str_split = malloc((nb_word + 1) * (sizeof(char *)));
	if (!str_split)
		return (0);
	str_split = mn_split(str_split, s, c);
	j = nb_word;
	while (nb_word--)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(str_split[i]), 0));
		free(str_split[i++]);
	}
	free(str_split);
	ft_nbdup(*stack_a);
	return (i);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	b;
	int	a;

	i = 0;
	while (i < size)
	{
		a = i + 1;
		while (a < size)
		{
			if (tab[i] > tab[a])
			{
				b = tab[i];
				tab[i] = tab[a];
				tab[a] = b;
			}
			a++;
		}
		i++;
	}
}

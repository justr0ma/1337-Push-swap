/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:24:42 by halaqoh           #+#    #+#             */
/*   Updated: 2022/03/25 01:57:09 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pmin(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	l;

	i = 0;
	l = ft_min(*stack_a);
	if (l <= 3)
	{
		while (i < l - 1)
		{
			rab(stack_a, "ra\n");
			i++;
		}
		pab(stack_a, stack_b, "pb\n");
	}
	else
	{
		if (l != ft_lstsize(*stack_a))
		{
			rrab(stack_a, "rra\n");
			i++;
		}
		rrab(stack_a, "rra\n");
		pab(stack_a, stack_b, "pb\n");
	}
}

void	ft_sort3(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
	{
		if ((*stack_a)->next->content < (*stack_a)->next->next->content)
			rab(stack_a, "ra\n");
		else
			if (sab(*stack_a, "sa\n"))
				rrab(stack_a, "rra\n");
	}
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		sab(*stack_a, "sa\n");
		rab(stack_a, "ra\n");
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		|| (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		if ((*stack_a)->next->content < (*stack_a)->next->next->content)
			sab(*stack_a, "sa\n");
		else
			rrab(stack_a, "rra\n");
	}
}

int	ft_sort5(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 1)
		exit(0);
	else if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sab(*stack_a, "sa\n");
	}
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort3(stack_a);
	else
	{
		if (ft_lstsize(*stack_a) == 5)
			ft_pmin(stack_a, stack_b);
		ft_pmin(stack_a, stack_b);
		ft_sort3(stack_a);
		pab(stack_b, stack_a, "pa\n");
		pab(stack_b, stack_a, "pa\n");
	}
	return (1);
}

void	ft_indexsorted(t_list *stack_a, int *tmp)
{
	int		i;
	int		j;
	int		a;
	t_list	*tmplst;

	i = 0;
	tmplst = stack_a;
	while (tmplst)
	{
		tmp[i++] = tmplst->content;
		tmplst = tmplst->next;
	}
	ft_sort_int_tab(tmp, i);
	a = ft_lstsize(stack_a);
	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < a)
			if (stack_a->content == tmp[j++])
				stack_a->index = j - 1;
		stack_a = stack_a->next;
		i++;
	}
}

int	ft_check_sorted(t_list *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (1);
		stack_a = stack_a->next;
	}
	exit(0);
}

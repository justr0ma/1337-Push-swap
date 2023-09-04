/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:28:57 by halaqoh           #+#    #+#             */
/*   Updated: 2022/03/29 23:15:41 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r_rr(t_list **stack_a, int max, int l)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp->index > max)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < l)
		while ((*stack_a)->index != tmp->index)
			rab(stack_a, "ra\n");
	else
		while ((*stack_a)->index != tmp->index)
			rrab(stack_a, "rra\n");
}

void	ft_r_rr_2(t_list **stack_b, int nbr)
{
	t_list	*tmp;
	int		i;
	int		l;

	tmp = *stack_b;
	i = 0;
	while (tmp->index != nbr)
	{
		tmp = tmp->next;
		i++;
	}
	l = ft_lstsize(*stack_b) / 2;
	if (i < l)
		while ((*stack_b)->index != tmp->index)
			rab(stack_b, "rb\n");
	else
		while ((*stack_b)->index != tmp->index)
			rrab(stack_b, "rrb\n");
}

void	ft_p_ba(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_b))
	{		
		if (ft_lstlast(*stack_a)->index == ((*stack_a)->index - 1))
			rrab(stack_a, "rra\n");
		else if ((*stack_b)->index == (*stack_a)->index - 1)
			pab(stack_b, stack_a, "pa\n");
		else if ((*stack_b)->index < (*stack_a)->index
			&& (*stack_b)->index > ft_lstlast(*stack_a)->index)
		{
			pab(stack_b, stack_a, "pa\n");
			rab(stack_a, "ra\n");
		}
		else
		{
			ft_r_rr_2(stack_b, (*stack_a)->index - 1);
			pab(stack_b, stack_a, "pa\n");
		}
	}
	while (ft_lstlast(*stack_a)->index != -1)
		rrab(stack_a, "rra\n");
}

void	ft_sortall(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		max;
	int		m;
	int		i;
	int		l;

	i = 0;
	while (ft_lstsize(*stack_a) > 5)
	{
		l = ft_lstsize(*stack_a) / 2;
		min = ft_min_index(*stack_a);
		max = min + ((ft_lstsize(*stack_a) - 5) / 4);
		m = (max + min) / 2;
		while (i <= max)
		{
			ft_r_rr(stack_a, max, l);
			pab(stack_a, stack_b, "pb\n");
			if ((*stack_b)->index > m)
				rab(stack_b, "rb\n");
			i++;
		}
	}
	ft_sort5(stack_a, stack_b);
	ft_lstlast(*stack_a)->index = -1;
	ft_p_ba(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*tmp;
	int		ij[2];

	stack_a = NULL;
	stack_b = NULL;
	ij[0] = 0;
	ij[1] = 1;
	if (argc < 2)
		exit(0);
	while (argv[ij[1]] && argc > 1)
		ij[0] += ft_split(argv[ij[1]++], ' ', &stack_a);
	ft_check_sorted(stack_a);
	if (ij[0] < 6 && argc > 1)
		ft_sort5(&stack_a, &stack_b);
	else if (argc > 1)
	{
		tmp = malloc(sizeof(int) * ij[0]);
		ft_indexsorted(stack_a, tmp);
		ft_sortall(&stack_a, &stack_b);
		free(tmp);
	}
	ft_free(stack_a);
}

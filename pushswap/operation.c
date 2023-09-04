/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:31:43 by halaqoh           #+#    #+#             */
/*   Updated: 2022/03/22 10:25:33 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sab(t_list *stack_ab, char *operation)
{
	int	tmp;
	int	idx;

	if (ft_lstsize(stack_ab) > 1)
	{
		tmp = stack_ab->content;
		idx = stack_ab->index;
		stack_ab->content = stack_ab->next->content;
		stack_ab->index = stack_ab->next->index;
		stack_ab->next->content = tmp;
		stack_ab->next->index = idx;
		ft_printf("%s", operation);
	}
	return (1);
}

void	pab(t_list **stack_1, t_list **stack_2, char *operation)
{
	if (ft_lstsize(*stack_1) > 0)
	{
		ft_lstadd_front(stack_2,
			ft_lstnew((*stack_1)->content, (*stack_1)->index));
		*stack_1 = del_first(*stack_1);
		ft_printf("%s", operation);
	}
}

void	rab(t_list **stack_ab, char *operation)
{
	ft_lstadd_back(stack_ab,
		ft_lstnew((*stack_ab)->content, (*stack_ab)->index));
	*stack_ab = del_first(*stack_ab);
	ft_printf("%s", operation);
}

void	rrab(t_list **stack_ab, char *operation)
{
	t_list	*tmp;
	t_list	*lastnode;

	ft_lstadd_front(stack_ab, ft_lstnew((ft_lstlast(*stack_ab))->content,
			(ft_lstlast(*stack_ab))->index));
	tmp = *stack_ab;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	lastnode = tmp->next;
	tmp->next = NULL;
	free(lastnode);
	ft_printf("%s", operation);
}

int	ft_min_index(t_list *stack_a)
{
	int	min;
	int	i;

	i = 0;
	min = stack_a->index;
	while (stack_a)
	{
		i++;
		if (min > stack_a->index)
		{
			min = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	return (min);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halaqoh <halaqoh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:10:08 by halaqoh           #+#    #+#             */
/*   Updated: 2022/03/16 12:29:51 by halaqoh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content, int index)
{
	t_list	*p;

	p = NULL;
	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->content = (int)content;
	p->index = index;
	p->next = NULL;
	return (p);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*n;
	t_list	*current;

	n = lst;
	current = NULL;
	while (n)
	{
		current = n;
		n = n->next;
	}
	return (current);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*n;

	i = 0;
	n = lst;
	while (n)
	{
		n = n->next;
		i++;
	}
	return (i);
}

t_list	*del_first(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	stack = stack->next;
	free(tmp);
	return (stack);
}

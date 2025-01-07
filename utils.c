/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:03:13 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/07 16:02:52 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sl	*shift(t_sl **list)
{
	t_sl	*og_list;
	t_sl	*shifted;

	og_list = *list;
	if (!og_list)
		return (NULL);
	if (!og_list->next)
	{
		*list = NULL;
		return (og_list);
	}
	shifted = og_list;
	og_list = og_list->next;
	*list = og_list;
	shifted->next = NULL;
	return (shifted);
}

void	unshift(t_sl **list, t_sl *new)
{
	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	new->next = *list;
	*list = new;
}

t_sl	*pop(t_sl **list)
{
	t_sl	*popped;
	t_sl	*current;

	if (!list)
		return (NULL);
	current = *list;
	popped = current->next;
	while (popped->next)
	{
		current = popped;
		popped = popped->next;
	}
	current->next = NULL;
	return (popped);
}

void	push_back(t_sl **list, t_sl *new)
{
	t_sl	*tmp;

	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	if (!*list && !new)
		return ;
	tmp = lst_last(*list);
	tmp->next = new;
}

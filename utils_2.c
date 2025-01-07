/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:25:09 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/07 16:06:35 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_sl	*new_list(int val)
{
	t_sl	*newlist;

	newlist = (t_sl *)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->value = val;
	newlist->next = NULL;
	return (newlist);
}

void	clear_list(t_sl **list)
{
	t_sl	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = *list;
		*list = tmp->next;
		free(&tmp->value);
		free(&tmp->rank);
		free(tmp);
	}
	*list = NULL;
}

int	list_size(t_sl *lst)
{
	int		i;
	t_sl	*tmp;

	if (lst)
	{
		tmp = lst;
		i = 1;
		while (tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
		return (i);
	}
	return (0);
}

t_sl	*lst_last(t_sl *lst)
{
	t_sl	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:30:20 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/07 15:54:01 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_sl **list)
{
	int		buffer_val;
	int		buffer_rank;
	t_sl	*temp;

	temp = *list;
	if (!temp || !temp->next)
		return ;
	buffer_val = temp->value;
	buffer_rank = temp->rank;
	temp->value = temp->next->value;
	temp->rank = temp->next->rank;
	temp->next->value = buffer_val;
	temp->next->rank = buffer_rank;
}

void	rotate(t_sl **list, int dir)
{
	t_sl	*temp;

	if (!*list)
		return ;
	if (dir == -1)
	{
		temp = pop(list);
		unshift(list, temp);
	}
	else
	{
		temp = shift(list);
		push_back(list, temp);
	}
}

void	push(t_sl **dest, t_sl	**src)
{
	t_sl	*temp;

	temp = shift(src);
	unshift(dest, temp);
}

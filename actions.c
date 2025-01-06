/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:30:20 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/06 11:39:55 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	void	*buffer;
	t_list	*temp;

	temp = *list;
	if (!temp || !temp->next)
		return ;
	buffer = temp->content;
	temp->content = temp->next->content;
	temp->next->content = buffer;
}

t_list	*shift(t_list **list)
{
	t_list	*og_list;
	t_list	*shifted;

	og_list = *list;
	if (!og_list || !og_list->next)
		return (NULL);
	shifted = og_list;
	og_list = og_list->next;
	*list = og_list;
	shifted->next = NULL;
	return (shifted);
}

t_list	*pop(t_list **list)
{
	t_list	*popped;
	t_list	*current;

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

void	rotate(t_list **list, int dir)
{
	t_list	*temp;

	if (!*list)
		return ;
	if (dir == -1)
	{
		temp = pop(list);
		ft_lstadd_front(list, temp);
	}
	else
	{
		temp = shift(list);
		ft_lstadd_back(list, temp);
	}
}

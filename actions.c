/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:30:20 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/03 18:40:23 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	swap(t_list *list)
{
	void	*buffer;

	if (!list || !list->next)
		return (0);
	buffer = list->content;
	list->content = list->next->content;
	list->next->content = buffer;
	ft_printf("sa\n");
	return (1);
}

t_list	*rotate(t_list *list, int reverse)
{
	t_list	*current;

	if (!list || !list->next)
		return (NULL);
	if (reverse)
	{
		current = list;
		while (current->next && current->next != list)
			current = current->next;
		current->next = list;
		ft_printf("rra\n");
		return (current);
	}
	else
	{
		ft_printf("ra\n");
		return (list->next);
	}
}

//create pop function and split push in 2 parts
int	push(t_list **source, t_list **destination)
{
	t_list	*temp;
	t_list	*next;
	t_list	*src;
	t_list	*dest;

	src = *source;
	dest = *destination;
	if (!src || !src->content)
		return (0);
	temp = src;
	next = src->next;
	src = rotate(src, 1);
	src->next = next;
	*source = next;
	next = NULL;
	if (dest)
	{
		if (dest->next)
			next = dest->next;
		dest = rotate(dest, 1);
		dest->next = temp;
		temp->next = next;
	}
	else
	{
		dest = temp;
		dest->next = dest;
	}
	*destination = dest;
	return (1);
}

void	print_list(t_list *list)
{
	int		start;
	t_list	*current;
	int		current_int;

	current = list;
	start = 0;
	while (current != list || !start)
	{
		start = 1;
		current_int = *(int *)current->content;
		ft_printf("-%d-\n", current_int);
		current = current->next;
		if (!current)
			break ;
	}
}

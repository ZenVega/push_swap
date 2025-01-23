/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:18:55 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 17:01:23 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "libft/libft.h"

int	handle_error(t_obj *sobj)
{
	if (sobj->a)
		clear_list(&sobj->a);
	if (sobj->b)
		clear_list(&sobj->b);
	free(sobj);
	ft_printf("Error\n");
	return (0);
}

void	print_sl(t_sl *list)
{
	int		start;
	t_sl	*current;

	if (list == NULL)
	{
		ft_printf("LIST EMPTY");
		return ;
	}
	current = list;
	start = 0;
	while (current != list || !start)
	{
		start = 1;
		ft_printf("Val:%d || Rank:%d\n", current->value, current->rank);
		current = current->next;
		if (!current)
			break ;
	}
}

int	rank_list(t_sl **list)
{
	t_sl	*current;
	t_sl	*comp;
	int		rank;
	int		rank_max;

	rank = 0;
	rank_max = 0;
	current = *list;
	comp = current->next;
	while (current && comp)
	{
		while (comp)
		{
			if (current->value > comp->value)
				rank++;
			comp = comp->next;
		}
		current->rank = rank;
		if (rank > rank_max)
			rank_max = rank;
		rank = 0;
		current = current->next;
		comp = *list;
	}
	return (rank_max + 1);
}

int	main(int argc, char **argv)
{
	t_obj	*sobj;

	sobj = (t_obj *)malloc(sizeof(t_obj));
	if (argc < 2 || !sobj)
	{
		free(sobj);
		return (1);
	}
	sobj->a = NULL;
	sobj->b = NULL;
	if (!create_list(&sobj->a, argc, argv))
		return (handle_error(sobj));
	sobj->len_a = rank_list(&sobj->a);
	sobj->len_b = 0;
	if (!sobj->len_a)
		return (handle_error(sobj));
	solve_turk(sobj);
	clear_list(&sobj->a);
	clear_list(&sobj->b);
	free(sobj);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:46:02 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/08 11:17:55 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	validate(char *input)
{
	if (*input == '-')
		input++;
	while (*input)
	{
		if (!ft_isdigit(*input))
			return (0);
		input++;
	}
	if (*input == 0)
		return (1);
	else
		return (0);
}

int	check_dup(t_sl **list)
{
	t_sl	*current;
	t_sl	*comp;

	current = *list;
	comp = current->next;
	while (current && comp)
	{
		while (comp != NULL && current->value != comp->value)
			comp = comp->next;
		if (comp)
			return (0);
		current = current->next;
		comp = current->next;
	}
	return (1);
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

int	handle_error(t_sl **list)
{
	if (list != NULL)
		clear_list(list);
	ft_printf("Error\n");
	return (0);
}

int	create_list(t_sl **list, int argc, char **argv)
{
	int		i;
	t_sl	*new;
	char	**input;

	i = 0;
	if (argc == 2)
		input = ft_split((const char *)argv[1], ' ');
	else
		input = argv + 1;
	while (input[i])
	{
		if (!validate(input[i]))
			return (0);
		new = new_list(0);
		if (!valtoi(&new->value, input[i]))
			return (0);
		push_back(list, new);
		i++;
	}
	if (!check_dup(list))
		return (0);
	return (rank_list(list));
}

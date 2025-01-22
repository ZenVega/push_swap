/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:46:02 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/22 16:45:06 by uschmidt         ###   ########.fr       */
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

int	free_input(char **input, t_sl *lst, int is_split)
{
	int		i;

	i = 0;
	if (input && is_split)
	{
		while (input[i])
			free(input[i++]);
		free(input);
	}
	if (lst)
		free(lst);
	return (0);
}

int	fill_list(t_sl **list, char	**input, int is_split)
{
	t_sl	*new;
	int		i;

	i = 0;
	while (input[i])
	{
		new = new_list(0);
		if (!new)
			return (free_input(input, NULL, is_split));
		if (!validate(input[i]))
			return (free_input(input, new, is_split));
		if (!valtoi(&new->value, input[i]))
			return (free_input(input, new, is_split));
		push_back(list, new);
		i++;
	}
	return (1);
}

int	create_list(t_sl **list, int argc, char **argv)
{
	int		is_split;
	char	**input;

	is_split = 0;
	if (argc == 2)
	{
		is_split = 1;
		input = ft_split((const char *)argv[1], ' ');
	}
	else
		input = argv + 1;
	if (argc == 2 && (!input || !input[0]))
		return (free_input(input, NULL, is_split));
	if (!fill_list(list, input, is_split))
		return (0);
	if (!check_dup(list))
	{
		free_input(input, NULL, is_split);
		clear_list(list);
		return (0);
	}
	if (argc == 2)
		free_input(input, NULL, is_split);
	return (1);
}

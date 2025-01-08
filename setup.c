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
		while (comp && current->value != comp->value)
			comp = comp->next;
		if (comp)
			return (0);
		current = current->next;
		comp = current->next;
	}
	return (1);
}

int	log_error(void)
{
	ft_printf("Error\n");
	return (0);
}

int	create_list(t_sl **list, int argc, char **argv)
{
	int		i;
	t_sl	*new;
	char	**input;

	i = 1;
	if (argc == 2)
		input = ft_split((const char *)argv, ' ');
	else
		input = argv;
	while (input[i])
	{
		if (!validate(input[i]))
		{
			clear_list(list);
			return (0);
		}
		new = new_list(ft_atoi(input[i]));
		push_back(list, new);
		i++;
	}
	return (check_dup(list));
}

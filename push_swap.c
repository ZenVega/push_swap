/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:18:55 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/06 14:03:58 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "ft_printf/ft_printf.h"

void	print_list(t_list *list)
{
	int		start;
	t_list	*current;
	int		current_int;

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
		current_int = *(int *)current->content;
		ft_printf("-%d-\n", current_int);
		current = current->next;
		if (!current)
			break ;
	}
}

void	create_list(t_list	**list, int argc, char **argv)
{
	int		i;
	int		*as_int;
	t_list	*new;

	ft_printf("Create List\n");
	i = 1;
	while (i < argc)
	{
		as_int = (int *)malloc(sizeof(int));
		if (!as_int)
			ft_lstclear(list, free);
		*as_int = ft_atoi(argv[i]);
		new = ft_lstnew(as_int);
		ft_printf("Int: %d\n", *as_int);
		ft_lstadd_back(list, new);
		i++;
	}
	ft_printf("List Created\n");
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	create_list(&list_a, argc, argv);
	if (argc < 2)
		return (0);
	call_action("pb", &list_a, &list_b);
	call_action("pb", &list_a, &list_b);
	ft_printf("LA After PUSH\n");
	print_list(list_a);
	ft_printf("LA After PUSH\n");
	print_list(list_b);
	call_action("ss", &list_a, &list_b);
	ft_printf("LA After ROTATE\n");
	print_list(list_a);
	ft_printf("LB After ROTATE\n");
	print_list(list_b);
	ft_lstclear(&list_a, free);
	ft_lstclear(&list_b, free);
	return (0);
}

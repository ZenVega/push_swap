/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:32:07 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/08 11:15:41 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_sl
{
	int			value;
	int			rank;
	struct s_sl	*next;
}	t_sl;

typedef struct s_obj
{
	t_sl	*a;
	t_sl	*b;
	int		len_a;
	int		len_b;
}	t_obj;

//utils.c
t_sl	*shift(t_sl **list);
void	unshift(t_sl **list, t_sl *new);
t_sl	*pop(t_sl **list);
void	push_back(t_sl **list, t_sl *new);
int		valtoi(int *dest, const char *nptr);

//utils_2.c
int		clear_list(t_sl **list);
t_sl	*new_list(int val);
int		list_size(t_sl *lst);
t_sl	*lst_last(t_sl *lst);

//setup.c
int		create_list(t_sl **list, int argc, char **argv);
int		handle_error(t_sl **list);

//actions.c
void	swap(t_sl **list);
void	rotate(t_sl **list, int dir);
void	push(t_sl **dest, t_sl	**src);
void	print_sl(t_sl *list);

//call_actions.c
void	call_action(char *Iid, t_obj *sobj);
void	swap_list(t_obj *sobj, char *id);
void	rotate_list(t_obj *sobj, char *id);
void	push_list(t_obj *sobj, char *id);

//simple_solve.c
void	solve_simple(t_obj *sobj, int len);

#endif

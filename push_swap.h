/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:32:07 by uschmidt          #+#    #+#             */
/*   Updated: 2025/01/06 14:02:34 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

void	swap(t_list **list);
t_list	*shift(t_list **list);
t_list	*pop(t_list **list);
void	rotate(t_list **list, int dir);
void	print_list(t_list *list);
void	push(t_list **dest, t_list	**src);

void	call_action(char *ID, t_list **a, t_list **b);
void	swap_list(t_list **a, t_list **b, char list_id);
void	rotate_list(t_list **a, t_list **b, char list_id, int dir);
void	push_list(t_list **dest, t_list	**src, char list_id);
#endif

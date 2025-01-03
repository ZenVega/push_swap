/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uschmidt <uschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:41:43 by uschmidt          #+#    #+#             */
/*   Updated: 2024/11/27 16:00:27 by uschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_putnbr_base(long long nbr, char *base);
void	ft_putull_base(unsigned long long nbr, char *base, int cnt, int radix);
int		ft_printptr(void *ptr);
int		ft_printchar(char c);
int		ft_printstr(char *c);
int		ft_printnbr(long long nbr);
int		ft_printprcnt(void);

#endif

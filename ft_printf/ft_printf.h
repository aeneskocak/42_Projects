/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkocak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:33:06 by ahkocak           #+#    #+#             */
/*   Updated: 2022/05/25 17:33:09 by ahkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		format(char type, va_list list);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printint(int nbr);
int		ft_printuint(unsigned int nbr);
int		ft_printhexa(unsigned long nbr, int s);

#endif

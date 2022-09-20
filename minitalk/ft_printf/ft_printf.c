/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkocak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:37:08 by ahkocak           #+#    #+#             */
/*   Updated: 2022/05/25 17:37:12 by ahkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char type, va_list list)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_printchar(va_arg(list, int));
	else if (type == 's')
		len += ft_printstr(va_arg(list, char *));
	else if (type == 'i' || type == 'd')
		len += ft_printint(va_arg(list, int));
	else if (type == 'u')
		len += ft_printuint(va_arg(list, unsigned int));
	else if (type == '%')
		len += ft_printchar('%');
	else if (type == 'x')
		len += ft_printhexa(va_arg(list, unsigned), 1);
	else if (type == 'X')
		len += ft_printhexa(va_arg(list, unsigned), 2);
	else if (type == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_printhexa(va_arg(list, unsigned long), 1);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	va_start (list, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += write(1, &str[i], 1);
		else if (str[i] == '%')
			len += format(str[++i], list);
		i++;
	}
	va_end(list);
	return (len);
}

//write function returns the length of the string and declaring it to len

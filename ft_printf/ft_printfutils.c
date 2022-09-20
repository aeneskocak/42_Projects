/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkocak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:37:55 by ahkocak           #+#    #+#             */
/*   Updated: 2022/05/25 17:37:59 by ahkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}
//printing char

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
//printing chars in str[] one by one.

int	ft_printint(int nbr)
{
	int		len;
	long	lnbr;

	len = 0;
	lnbr = nbr;
	if (lnbr < 0)
	{
		lnbr = -lnbr;
		len += write (1, "-", 1);
	}
	if (lnbr >= 10)
	{
		len += ft_printint(lnbr / 10);
		len += ft_printint(lnbr % 10);
	}
	else if (lnbr < 10)
		len += ft_printchar(lnbr + 48);
	return (len);
}
//recursive function

int	ft_printuint(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
	{
		len += ft_printint(nbr / 10);
		len += ft_printint(nbr % 10);
	}
	else if (nbr < 10)
		len += ft_printchar(nbr + 48);
	return (len);
}

int	ft_printhexa(unsigned long nbr, int s)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_printhexa(nbr / 16, s);
		len += ft_printhexa(nbr % 16, s);
	}
	if (nbr < 16)
	{
		if (nbr <= 9)
			len += ft_printchar(nbr + 48);
		else
		{
			if (s == 1)
				len += ft_printchar(nbr + 87);
			else
				len += ft_printchar(nbr + 55);
		}
	}
	return (len);
}

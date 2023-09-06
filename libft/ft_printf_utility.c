/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:46:05 by ohassyao          #+#    #+#             */
/*   Updated: 2022/12/22 13:49:13 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		write (1, str++, 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putchar('-');
		i += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		i += ft_putchar(48 + n);
	}
	return (i);
}

int	ft_putnbr_uns(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb < 10)
		i += ft_putchar(nb + 48);
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	return (i);
}

int	ft_hexa(unsigned int nb, char c)
{
	int		i;
	char	*s;

	i = 0;
	if (nb < 16)
	{
		if (c == 'x')
		{
			s = "0123456789abcdef";
			i += ft_putchar(s[nb]);
		}
		else if (c == 'X')
		{
			s = "0123456789ABCDEF";
			i += ft_putchar(s[nb]);
		}
	}
	else
	{
		i += ft_hexa((nb / 16), c);
		i += ft_hexa((nb % 16), c);
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:26:51 by ohassyao          #+#    #+#             */
/*   Updated: 2022/12/22 13:48:55 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexavoid(unsigned long long nb)
{
	int		i;
	char	*s;

	i = 0;
	if (nb < 16)
	{
		s = "0123456789abcdef";
		i += ft_putchar(s[nb]);
	}
	else
	{
		i += ft_hexavoid(nb / 16);
		i += ft_hexavoid(nb % 16);
	}
	return (i);
}

int	ft_checker(va_list *ptr, const char *str, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(*ptr, int));
	else if (str[i] == 's')
		count += ft_putstr(va_arg(*ptr, char *));
	else if (str[i] == 'p')
	{
		count += ft_putstr("0x");
		count += ft_hexavoid(va_arg(*ptr, unsigned long long));
	}
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_putnbr(va_arg(*ptr, int));
	else if (str[i] == 'u')
		count += ft_putnbr_uns(va_arg(*ptr, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_hexa(va_arg(*ptr, unsigned int), str[i]);
	else if (str[i] == '%')
		count += write (1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		j;

	if (!str)
		return (0);
	va_start(list, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
			j += ft_checker(&list, str, ++i);
		else
			j += ft_putchar(str[i]);
		i++;
	}
	va_end(list);
	return (j);
}

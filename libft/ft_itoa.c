/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:29:04 by ohassyao          #+#    #+#             */
/*   Updated: 2022/03/21 17:37:22 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlenght(int nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		++count;
	while (nb && ++count)
		nb /= base;
	return (count);
}

char	*ft_itoa(int nb)
{
	int			lenght;
	char		*str;
	const char	*digits = "0123456789";

	lenght = ft_numlenght(nb, 10);
	str = malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return (0);
	str[lenght] = 0;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		str[0] = '-';
	while (nb)
	{
		if (nb > 0)
			str[--lenght] = digits[nb % 10];
		else
			str[--lenght] = digits[nb % 10 * -1];
		nb /= 10;
	}
	return (str);
}

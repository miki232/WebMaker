/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:10:25 by ohassyao          #+#    #+#             */
/*   Updated: 2022/03/20 16:50:08 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	value;
	unsigned char		*s;

	s = (unsigned char *)str;
	value = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v'
		|| *s == '\f' || *s == '\r')
		s++;
	if (*s == '-' || *s == '+')
		if (*(s++) == '-')
			sign *= -1;
	while (*s >= '0' && *s <= '9')
	{
		value *= 10;
		value += *s - '0';
		s++;
	}
	return (value * sign);
}

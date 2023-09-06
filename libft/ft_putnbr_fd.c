/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:40:57 by ohassyao          #+#    #+#             */
/*   Updated: 2022/03/22 17:58:29 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printer(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		printer('8', fd);
	}
	else if (n < 0)
	{
		printer('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n <= 9)
			printer(n + '0', fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			printer((n % 10) + '0', fd);
		}
	}
}

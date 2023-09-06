/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:29:08 by ohassyao          #+#    #+#             */
/*   Updated: 2022/03/27 18:11:40 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while ((s1[c] || s2[c]) && n--)
	{
		if (s1[c] != s2[c])
		{
			return (*(unsigned char *)&s1[c] - *(unsigned char *)&s2[c]);
		}
		c++;
	}
	return (0);
}

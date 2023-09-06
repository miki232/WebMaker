/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:36:28 by ohassyao          #+#    #+#             */
/*   Updated: 2022/03/27 19:40:54 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	lenght;
	char	*s2;

	lenght = ft_strlen(s1);
	s2 = malloc(lenght + 1);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, lenght);
	s2[lenght] = '\0';
	return (s2);
}

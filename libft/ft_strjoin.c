/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:12:15 by ohassyao          #+#    #+#             */
/*   Updated: 2022/03/27 19:34:34 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		total_len;
	char		*str;

	if (s1 && s2)
	{
		total_len = ft_strlen(s1) + ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (total_len + 1));
		if (!str)
			return (0);
		i = 0;
		j = 0;
		while (s1[j])
			str[i++] = s1[j++];
		j = 0;
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		return (str);
	}
	return (0);
}

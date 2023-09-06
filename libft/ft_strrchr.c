/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:04:53 by ohassyao          #+#    #+#             */
/*   Updated: 2022/03/27 19:53:08 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	size_t	max_lenght;
	char	*last;

	index = 0;
	max_lenght = ft_strlen(s);
	last = NULL;
	while (index <= max_lenght)
	{
		if (s[index] == (unsigned char) c)
			last = (char *)(s + index);
		if (s[index] == '\0')
			break ;
		index++;
	}
	return (last);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:13:11 by ohassyao          #+#    #+#             */
/*   Updated: 2022/03/17 17:13:32 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	counter;
	size_t	ndx;

	counter = 0;
	ndx = 0;
	while (src[counter] != '\0')
		counter++;
	if (size > 0)
	{
		while (src[ndx] != '\0' && ndx < (size - 1))
		{
			dest[ndx] = src[ndx];
			ndx++;
		}
		dest[ndx] = '\0';
	}
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassyao <ohassyao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:12:55 by ohassyao          #+#    #+#             */
/*   Updated: 2022/12/22 13:36:44 by ohassyao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_gnl(char *s, unsigned int start, size_t len, int need_free)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	if (ft_strlen(s) <= len)
		str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start < (unsigned int) ft_strlen(s))
	{
		while (i < len && s[start] != '\0')
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	str[i] = '\0';
	if (need_free)
		free(s);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

int	ft_srch(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_readnsave(int fd, char *saved)
{
	int		readbytes;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(saved, '\n'))
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1 || readbytes == 0)
			break ;
		buffer[readbytes] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	if (ft_strlen(saved) == 0)
	{
		free(saved);
		return (NULL);
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	if (!saved)
		saved = ft_strdup("");
	saved = ft_readnsave(fd, saved);
	if (!saved)
		return (0);
	line = ft_substr_gnl(saved, 0, ft_srch(saved, '\n') + 1, 0);
	saved = ft_substr_gnl(saved, ft_srch(saved, '\n') + 1,
			ft_strlen(saved), 1);
	return (line);
}

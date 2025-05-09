/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpuerto- <jpuerto-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:25:36 by jpuerto-          #+#    #+#             */
/*   Updated: 2025/02/24 13:58:09 by jpuerto-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*str;
	int		i;
	int		j;

	if (!stash || !buff)
		return (NULL);
	str = ft_calloc(sizeof(char), ft_strlen(stash) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		str[i + j] = buff[j];
		j++;
	}
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl;

	if (fd < 0)
		return (NULL);
	gnl.line = ft_calloc(sizeof(char), 1);
	if (!gnl.line)
		return (NULL);
	gnl.i = 0;
	while (1)
	{
		if (gnl.buffer_pos >= gnl.bytes_read)
		{
			gnl.bytes_read = read(fd, gnl.buffer, 1024);
			gnl.buffer_pos = 0;
			if (gnl.bytes_read <= 0)
				break ;
		}
		gnl.line = ft_strjoin(gnl.line, gnl.buffer + gnl.buffer_pos);
		gnl.buffer_pos++;
		if (gnl.buffer[gnl.buffer_pos - 1] == '\n')
			break ;
	}
	if (gnl.line[0] == '\0')
		return (free(gnl.line), NULL);
	return (gnl.line);
}

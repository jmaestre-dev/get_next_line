/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaestre <jmaestre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:17:54 by username          #+#    #+#             */
/*   Updated: 2026/11/06 12:10:20 by jmaestre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_one_line(char *storage)
{
	int	i;

	i = 0;
	if (!storage || !storage[0])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	return (ft_substr(storage, 0, i));
}

char	*remove_from_storage(char *storage, char *line)
{
	char	*nstorage;
	size_t	i;

	if (!storage)
		return (NULL);
	i = ft_strlen(line);
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	nstorage = ft_substr(storage, i, ft_strlen(storage));
	free(storage);
	return (nstorage);
}

char	*free_storage(char *storage, char *buffer)
{
	free(buffer);
	free(storage);
	return (NULL);
}

char	*add_to_storage(char *storage, int fd)
{
	char	*buffer;
	char	*tmp;
	ssize_t	num_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	num_bytes = 1;
	while (num_bytes != 0 && !ft_strchr(storage, '\n'))
	{
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes == -1)
			return (free_storage(storage, buffer));
		if (num_bytes > 0)
		{
			buffer[num_bytes] = '\0';
			tmp = storage;
			storage = ft_strjoin(tmp, buffer);
			free(tmp);
		}
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = add_to_storage(storage, fd);
	if (!storage)
		return (NULL);
	line = get_one_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = remove_from_storage(storage, line);
	return (line);
}

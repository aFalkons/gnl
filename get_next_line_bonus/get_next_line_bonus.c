/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:01:38 by afalconi          #+#    #+#             */
/*   Updated: 2023/11/02 18:45:40 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*raw_string[1024];
	char		*next_line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	raw_string[fd] = get_the_line(fd, raw_string[fd]);
	if (!raw_string[fd])
		return (NULL);
	next_line = stop_at_newline(raw_string[fd]);
	raw_string[fd] = extract(raw_string[fd]);
	return (next_line);
}

char	*get_the_line(int fd, char *raw_string)
{
	char		*buf;
	ssize_t		buff_lenght;

	buff_lenght = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(raw_string, '\n') && buff_lenght != 0)
	{
		buff_lenght = read(fd, buf, BUFFER_SIZE);
		if (buff_lenght == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[buff_lenght] = '\0';
		raw_string = ft_strjoin(raw_string, buf);
	}
	free(buf);
	return (raw_string);
}

char	*stop_at_newline(char *raw_string)
{
	int			i;
	char		*line_to_return;

	i = 0;
	if (!raw_string[i])
		return (NULL);
	if (!ft_strchr(raw_string, '\n'))
		return (ft_strdup(raw_string));
	while (raw_string[i] && raw_string[i] != '\n')
		i++;
	line_to_return = (char *)malloc(++i + 1);
	if (!line_to_return)
		return (NULL);
	line_to_return[i] = '\0';
	i = 0;
	while (raw_string[i] && raw_string[i] != '\n')
	{
		line_to_return[i] = raw_string[i];
		i++;
	}
	if (raw_string[i] == '\n')
		line_to_return[i] = '\n';
	return (line_to_return);
}

char	*extract(char *raw_string)
{
	char		*backup;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (raw_string[i] != '\n' && raw_string[i])
		i++;
	if (!raw_string[i])
	{
		free(raw_string);
		return (NULL);
	}
	i++;
	backup = malloc(ft_strlen(raw_string + i) + 1);
	if (!backup)
		return (NULL);
	while (raw_string[i])
		backup[j++] = raw_string[i++];
	backup[j] = 0;
	free(raw_string);
	return (backup);
}

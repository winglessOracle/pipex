/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/18 14:43:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/12/20 12:51:14 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str(char *str)
{
	if (str)
		free (str);
}

char	*read_and_join(int fd, char *passed_line)
{
	ssize_t		bytes_read;
	char		buffer[BUFFER_SIZE + 1];

	bytes_read = 1;
	while (bytes_read != 0 && ft_findchr(passed_line, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free_str(passed_line);
			return (NULL);
		}
		if (bytes_read != 0)
		{
			buffer[bytes_read] = '\0';
			passed_line = ft_strjoin_gnl(passed_line, buffer);
			if (passed_line == NULL)
				return (NULL);
		}
	}
	return (passed_line);
}

char	*get_next_line(int fd)
{
	static char	*passed_line[MAX_OPEN];
	char		*return_line;

	return_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd > BUFFER_SIZE - 1)
		return (NULL);
	if (ft_findchr(passed_line[fd], '\n') == 0)
	{
		passed_line[fd] = read_and_join(fd, passed_line[fd]);
		if (passed_line[fd] == NULL || passed_line[fd][0] == '\0')
		{
			free_str(passed_line[fd]);
			passed_line[fd] = NULL;
			return (NULL);
		}
	}
	return_line = get_new_line(passed_line[fd]);
	if (!return_line || return_line[0] == '\0')
	{
		free_str(passed_line[fd]);
		passed_line[fd] = NULL;
		return (NULL);
	}
	passed_line[fd] = get_new_string(passed_line[fd]);
	return (return_line);
}

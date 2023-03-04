/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 09:49:34 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/12/20 12:50:58 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *passed_line, char *buffer)
{
	int		i;
	int		j;
	int		len_1;
	int		len_2;
	char	*joined_str;

	len_1 = ft_strlen_gnl(passed_line);
	len_2 = ft_strlen_gnl(buffer);
	joined_str = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!joined_str)
	{
		free_str(passed_line);
		return (NULL);
	}
	j = 0;
	i = 0;
	while (i < len_1)
		joined_str[i++] = passed_line[j++];
	j = 0;
	while (j < len_2)
		joined_str[i++] = buffer[j++];
	joined_str[i] = '\0';
	free(passed_line);
	return (joined_str);
}

char	*get_new_line(char *passed_line)
{
	char	*new_line;
	int		i;

	i = 0;
	while (passed_line[i] != '\n' && passed_line[i])
		i++;
	if (passed_line[i] != '\n')
		return (passed_line);
	else
	{
		new_line = (char *)malloc(sizeof(char) * (i + 2));
		if (!new_line)
			return (NULL);
	}
	i = 0;
	while (passed_line[i] != '\n' && passed_line[i])
	{
		new_line[i] = passed_line[i];
		i++;
	}
	new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*get_new_string(char *passed_line)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (passed_line[i] != '\n' && passed_line[i])
		i++;
	if (!passed_line[i] || passed_line == NULL)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(passed_line) - i));
	if (!new_str)
	{
		free_str(passed_line);
		passed_line = NULL;
		return (NULL);
	}
	j = 0;
	i += 1;
	while (i < ft_strlen_gnl(passed_line))
		new_str[j++] = passed_line[i++];
	new_str[j] = '\0';
	free(passed_line);
	return (new_str);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_findchr(char *str, char c)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

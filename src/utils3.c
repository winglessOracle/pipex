/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 12:45:47 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/18 19:03:33 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pop(char **arr, int index)
{
	int	i;

	if (arr == NULL)
		return ;
	i = index;
	while (arr[i])
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = NULL;
}

int	ft_last_char(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == c)
		return (1);
	return (0);
}

int	get_exit_st(t_data *data)
{
	int	waitstatus;
	int	i;

	i = 0;
	waitstatus = 0;
	while (i < data->num_proc)
	{
		waitpid(data->pids[i], &waitstatus, 0);
		i++;
	}
	return (WEXITSTATUS(waitstatus));
}

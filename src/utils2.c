/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 11:41:57 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/03 17:30:41 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_params(int argc, char **argv)
{
	if (argc != 5)
	{
		write(2, "four arguments required\n", 25);
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		return (0);
	else if (access(argv[1], R_OK) == -1)
	{
		write(2, "no file or no reading permission.\n", 35);
		return (2);
	}
	return (0);
}

void	ft_pop(char **arr, int index)
{
	int	i;

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

void	perror_exit(void)
{
	perror("error creating pipes");
	exit(errno);
}

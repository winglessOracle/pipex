/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_free.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 12:09:03 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/03 16:20:54 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	error_msg(int ret, char *msg, t_data *data)
{
	ft_printf("error %s", msg);
	if (data != 0)
	{
		free_all(data);
		close_all_pipes(data);
	}
	exit(ret);
}

void	free_all(t_data *data)
{
	ft_free(data->processes);
	ft_free_array_int(data->pipes);
	ft_free(data->pids);
	ft_free(data);
}

void	exit_make_here(t_data *data)
{
	perror("creating here_doc");
	ft_free_array_int(data->pipes);
	free(data);
	unlink("here_doc");
	exit(16);
}

int	check_path(char **envp)
{
	int	i;
	int	path;

	i = 0;
	path = 0;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path = 1;
	return (path);
}
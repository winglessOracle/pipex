/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 13:06:00 by carlo         #+#    #+#                 */
/*   Updated: 2023/03/18 19:03:03 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create_forks(char **envp, t_data *data)
{
	int	i;

	i = 0;
	data->pids = malloc(sizeof(int) * data->num_proc + 1);
	if (! data->pids)
		error_msg(18, "error: foking\n", data);
	while (i < data->num_proc)
	{
		data->pids[i] = fork();
		if (!data->pids || data->pids[i] == -1)
			error_msg(10, "error in fork process\n", data);
		if (data->pids[i] == 0)
		{
			close_pipes_child(i, data);
			set_pipes_child(i, data);
			close(data->pipes[i + 1][1]);
			close(data->pipes[i][0]);
			find_exec_cmd(i, envp, data);
			perror("unknown command or no permission\n");
			exit(127);
		}
		i++;
	}
	return (0);
}

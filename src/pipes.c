/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipes.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 12:11:24 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/07 12:25:22 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	**make_pipes(t_data *data)
{
	int	**pipes;
	int	p;

	p = 0;
	pipes = malloc(sizeof(int *) * (data->num_pipes + 1));
	if (!pipes)
		perror_exit();
	while (p < data->num_pipes)
	{
		pipes[p] = malloc(sizeof(int) * 2);
		if (!pipes[p++])
			perror_exit();
	}
	pipes[p] = NULL;
	p = 0;
	while (p < data->num_pipes)
	{
		if (pipe(pipes[p++]) == -1)
			perror_exit();
	}
	return (pipes);
}

void	close_pipes_child(int i, t_data *data)
{
	int	j;

	j = 0;
	while (j < data->num_pipes)
	{
		if (j != i)
			close(data->pipes[j][0]);
		if (j != i + 1)
			close(data->pipes[j][1]);
		j++;
	}
}

void	close_all_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_pipes)
	{
		close(data->pipes[i][0]);
		close(data->pipes[i][1]);
		i++;
	}
}

void	set_pipes_child(int i, t_data *data)
{
	if (data->num_proc == 1)
	{
		dup2(data->fd_in_file, STDIN_FILENO);
		dup2(data->fd_out_file, STDOUT_FILENO);
	}
	else
	{
		if (i == 0)
		{
			dup2(data->fd_in_file, STDIN_FILENO);
			dup2(data->pipes[i + 1][1], STDOUT_FILENO);
		}
		else if (i == data->num_proc - 1 && i != 0)
		{
			dup2(data->pipes[i][0], STDIN_FILENO);
			dup2(data->fd_out_file, STDOUT_FILENO);
		}
		else
		{
			dup2(data->pipes[i][0], STDIN_FILENO);
			dup2(data->pipes[i + 1][1], STDOUT_FILENO);
		}
	}
}

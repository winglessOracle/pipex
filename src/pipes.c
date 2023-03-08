/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipes.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 12:11:24 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/08 21:30:45 by carlo         ########   odam.nl         */
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
		perror_pipes(1);
	while (p < data->num_pipes)
	{
		pipes[p] = malloc(sizeof(int) * 2);
		if (!pipes[p++])
			perror_pipes(1);
	}
	pipes[p] = NULL;
	p = 0;
	while (p < data->num_pipes)
	{
		if (pipe(pipes[p++]) == -1)
			perror_pipes(1);
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
			if (close(data->pipes[j][0]) != 0)
				perror_pipes(2);
		if (j != i + 1)
			if (close(data->pipes[j][1]) != 0)
				perror_pipes(2);
		j++;
	}
}

void	close_all_pipes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_pipes)
	{
		if (close(data->pipes[i][0]) != 0)
			perror_pipes(2);
		if (close(data->pipes[i][1]) != 0)
			perror_pipes(2);
		i++;
	}
}


void	set_pipes_child(int i, t_data *data)
{
	if (data->num_proc == 1)
	{
		if (dup2(data->fd_in_file, STDIN_FILENO) != 0)
			perror_pipes(3);
		if (dup2(data->fd_out_file, STDOUT_FILENO) != 0)
			perror_pipes(3);
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

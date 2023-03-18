/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/31 11:41:57 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/18 19:03:24 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_data(int argc, char **argv, t_data *data)
{
	data->num_proc = argc - 3;
	data->num_pipes = argc - 2;
	data->pipes = make_pipes(data);
	if (ft_check_extention(argv[1], "here_doc") == 0)
	{
		make_here_doc(argv, data);
		data->fd_out_file = open(argv[data->num_pipes + 1],
				O_RDWR | O_CREAT | O_APPEND, 0644);
		data->fd_in_file = open("here_doc_temp", O_RDONLY, 0644);
	}
	else
	{
		data->fd_out_file = open(argv[data->num_pipes + 1],
				O_RDWR | O_CREAT | O_TRUNC, 0644);
		data->fd_in_file = open(argv[1], O_RDONLY, 0644);
	}
	if (data->fd_out_file < 0)
	{
		perror("error creating outfile\n");
		exit(4);
	}
	if (data->fd_in_file < 0)
		data->fd_in_file = open("here_doc_temp",
				O_RDWR | O_CREAT | O_TRUNC, 0644);
	return (0);
}

void	make_here_doc(char **argv, t_data *data)
{
	char	*line;
	int		fd;

	line = NULL;
	data->num_proc--;
	fd = open("here_doc_temp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (!fd)
		exit_make_here(data);
	while (1)
	{
		ft_printf("pipe heredoc> ");
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			exit_make_here(data);
		if (ft_strlen(line) >= 2 && ft_strncmp(line, argv[2],
				ft_strlen(line) - 1) == 0)
			break ;
		ft_putstr_fd(line, fd);
		free(line);
	}
	free(line);
	close(fd);
}

int	get_processes(char **argv, t_data *data)
{
	int	i;
	int	j;

	j = 2;
	if (ft_check_extention(argv[1], "here_doc") == 0)
		j++;
	data->processes = malloc(sizeof(char *) * (data->num_proc + 1));
	if (!data->processes)
		error_msg(5, "Error malloc processes\n", data);
	i = 0;
	while (i < data->num_proc)
		data->processes[i++] = argv[j++];
	data->processes[i] = NULL;
	return (0);
}

void	find_exec_cmd(int i, char **envp, t_data *data)
{
	char	**cmd_args;
	char	**my_directories;
	char	*cmd_path;
	int		j;

	j = 0;
	cmd_args = check_cmd_args(ft_split(data->processes[i], ' '));
	if (!(check_path(envp)))
		execve(cmd_args[0], cmd_args, NULL);
	else
	{
		while (envp[++j])
			if (ft_strncmp(envp[j], "PATH=", 5) == 0)
				my_directories = ft_split(envp[j] + 5, ':');
		check_my_dirs(my_directories, data);
		j = 0;
		while (my_directories[j++])
		{	
			my_directories[j] = ft_strjoin(my_directories[j], "/");
			cmd_path = ft_strjoin_free(my_directories[j], cmd_args[0]);
			execve(cmd_path, cmd_args, envp);
			ft_free(cmd_path);
		}
		execve(cmd_args[0], cmd_args, NULL);
	}
}

char	**check_cmd_args(char **cmd_args)
{
	int	i;

	if (!cmd_args)
		perror_pipes(4);
	i = 1;
	while (cmd_args[i])
	{
		if (cmd_args[i][0] == '\'')
		{
			while (ft_last_char(cmd_args[i], '\'') == 0)
			{
				cmd_args[i] = ft_strjoin_free(cmd_args[i], " ");
				cmd_args[i] = ft_strjoin_free(cmd_args[i], cmd_args[i + 1]);
				ft_pop(cmd_args, i + 1);
			}		
			cmd_args[i] = ft_strtrim(cmd_args[i], "'");
		}
		i++;
	}
	if (cmd_args == NULL)
		perror_pipes(4);
	return (cmd_args);
}

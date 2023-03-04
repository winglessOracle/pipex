/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 18:35:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/03 15:58:37 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_data
{
	char	**processes;
	int		**pipes;
	char	temp_file;
	int		num_proc;
	int		num_pipes;
	int		fd_out_file;
	int		fd_in_file;
	int		*pids;
}	t_data;

int		check_params(int argc, char **argv);
int		check_path(char **envp);
int		init_data(int argc, char **argv, t_data *data);
void	make_here_doc(char **argv, t_data *data);
int		get_processes(char **argv, t_data *data);
int		**make_pipes(t_data *data);
int		create_forks(char **envp, t_data *data);
void	close_pipes_child(int i, t_data *data);
void	set_pipes_child(int i, t_data *data);
char	**check_cmd_args(char **cmd_args);
void	find_exec_cmd(int i, char **envp, t_data *data);
void	close_all_pipes(t_data *data);
void	error_msg(int ret, char *msg, t_data *data);
void	exit_make_here(t_data *data);
int		ft_last_char(const char *str, const char c);
void	ft_pop(char **arr, int index);
int		get_exit_st(t_data *data);
void	perror_exit(void);
void	free_all(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 18:35:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/18 19:03:18 by carlo         ########   odam.nl         */
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
int		check_params_num(int argc, char **argv);
int		check_path(char **envp);
int		check_argv(int argc, char **argv);
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
int		check_my_dirs(char **my_directories, t_data *data);
int		ft_last_char(const char *str, const char c);
void	ft_pop(char **arr, int index);
int		get_exit_st(t_data *data);
void	perror_pipes(int select);
void	free_all(t_data *data);

#endif

/* error handeling
1: to few or too arguments passed in command line 
(four required and more allowd in bonus)
2: error creating directories for execve
3: malloc failed for data struct
4: could not get a file descriptor for infile or outfile
5: error allocating processes rows
6: error allocating processes cols
7: error allocating pipes rows
8: error allocating pipes cols
9: error creating pipes
10: failed to create forks
11: child did not execute. cmd unknown or no permission
12: failed to create pids for fork
13: faild to join string for execution command
14: failed to create here_doc file
15: exceded max input for limiter using here_doc
16: error creating here_doc
17: unknown command or no permission 
18: error allocating memory for fork
19: error in allocating memory for cmd_args
20 error closing pipes
21: error in dup 2 to redirect stdin or out
23: error. here_doc not in mandatory part
127: unkown command
*/
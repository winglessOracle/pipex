/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 18:01:01 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/08 19:52:45 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	leaks(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	int		exitstatus;

	exitstatus = 0;
	exitstatus = (check_params(argc, argv));
	if (exitstatus)
		return (exitstatus);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		perror("Failed malloc for data\n");
		return (3);
	}
	init_data(argc, argv, data);
	get_processes(argv, data);
	create_forks(envp, data);
	close_all_pipes(data);
	unlink("here_doc_temp");
	exitstatus = get_exit_st(data);
	free_all(data);
	return (exitstatus);
}

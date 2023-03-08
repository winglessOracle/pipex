/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 12:45:47 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/03/08 19:57:16 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_my_dirs(char **my_directories, t_data *data)
{
	if (!my_directories)
		error_msg(2, "error creating my_directories\n", data);
	return (0);
}

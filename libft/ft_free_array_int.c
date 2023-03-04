/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array_int.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 11:39:57 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/02/06 11:41:49 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array_int(int **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_free(arr[i]);
		i++;
	}
	free(arr);
	arr = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_params.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 12:33:10 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/02/02 14:37:06 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_params(int argc, char *argv, int n)
{
	if (argc != n)
	{
		ft_printf("ERROR\nInvalid arguments. Please use %n argument(s)\n", n);
		exit(EXIT_FAILURE);
	}
	if (ft_check_extention(argv, ".ber"))
	{
		ft_printf("ERROR\nInvalid file format. Please use a .ber file\n");
		exit(EXIT_FAILURE);
	}
}

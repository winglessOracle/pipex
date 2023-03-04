/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_chr_functions.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 14:58:24 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/11/01 12:34:11 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_char(t_print *list)
{
	char	c;

	c = va_arg(list->args, int);
	list->len += write(1, &c, 1);
}

void	ft_print_str(t_print *list)
{
	char	*str;

	str = va_arg(list->args, char *);
	if (!str)
	{
		list->len += write(1, "(null)", 6);
		return ;
	}
	while (*str)
	{
		list->len += write(1, &(*str), 1);
		str++;
	}
}

void	ft_print_str_dec(t_print *list, char *str)
{
	while (*str)
	{
		list->len += write(1, &(*str), 1);
		str++;
	}
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_dec_functions.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 09:56:33 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/11/01 13:25:08 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hex(t_print *list, char c)
{
	if (c == 'X')
		ft_printf_itoa_u(list, va_arg(list->args,
				unsigned int), list->base_h_up);
	else if (c == 'x')
		ft_printf_itoa_u(list, va_arg(list->args,
				unsigned int), list->base_h);
	else
	{
		list->len += write(1, "0x", 2);
		ft_printf_itoa_u(list, va_arg(list->args,
				unsigned long long int), list->base_h);
	}
}

void	ft_print_dec(t_print *list, char c)
{
	if (c == 'u')
		ft_printf_itoa_u(list, va_arg(list->args,
				unsigned int), list->base_d);
	else
		ft_printf_itoa(list, va_arg(list->args, int), list->base_d);
}

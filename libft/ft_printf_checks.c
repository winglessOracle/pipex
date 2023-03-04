/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_checks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 10:31:00 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/11/01 15:38:40 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_ident(t_print *list, char c)
{
	if (ft_strchr(list->valid_char, c))
		return (1);
	return (0);
}

int	check_input(t_print *list, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str [i + 1] == '%')
			i++;
		else if (str[i] == '%')
		{
			if (!(str [i + 1]))
				return (1);
			else if (!(check_ident(list, str[i + 1])))
				return (0);
		}
		i++;
	}
	return (1);
}

void	check_letter(t_print *list, char c)
{	
	if (c == 'c')
		ft_print_char(list);
	else if (c == 's')
		ft_print_str(list);
	else if (c == 'd' || c == 'i' || c == 'u')
		ft_print_dec(list, c);
	else if (c == 'x' || c == 'X' || c == 'p')
		ft_print_hex(list, c);
	else if (c == '%')
		list->len += write(1, "%", 1);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 10:24:39 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/11/01 16:40:29 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_print	*initialize_list(t_print *list)
{
	list->len = 0;
	list->valid_char = "cspdiuxX%";
	list->base_d = "0123456789";
	list->base_h = "0123456789abcdef";
	list->base_h_up = "0123456789ABCDEF";
	return (list);
}

static int	loop(t_print *list, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str [i + 1] == '\0')
				return (1);
			else
			{
				check_letter(list, str[i + 1]);
				i++;
			}
		}
		else
			list->len += write(1, &str[i], 1);
		if (str[i + 1])
			i++;
		else
			return (1);
	}
	return (1);
}

int	ft_printf(const char *str, ...)
{
	t_print		*list;
	int			ret;

	list = (t_print *)malloc(sizeof(t_print));
	if (!list)
		return (-1);
	initialize_list(list);
	va_start(list->args, str);
	if (!(check_input(list, (char *)str)))
	{
		va_end(list->args);
		free(list);
		return (-1);
	}
	loop(list, (char *)str);
	ret = list->len;
	va_end(list->args);
	free(list);
	return (ret);
}

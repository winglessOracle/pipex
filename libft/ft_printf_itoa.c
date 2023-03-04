/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_itoa.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 10:46:36 by cwesseli      #+#    #+#                 */
/*   Updated: 2022/11/01 13:29:42 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len_u(unsigned long long int num, int rad)
{	
	unsigned long long int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num != 0)
	{
		num /= rad;
		len++;
	}
	return (len);
}

static int	get_len(long int num, int rad)
{	
	long int	len;

	len = 0;
	if (num < 0)
		len++;
	while (num != 0)
	{
		num /= rad;
		len++;
	}
	return (len);
}

static void	if_zero(t_print *list)
{
	char	*ret;

	ret = ft_calloc(sizeof(char), 2);
	if (!ret)
		return ;
	ret[0] = '0';
	ft_print_str_dec(list, ret);
	free (ret);
}

void	ft_printf_itoa(t_print *list, long int n, char *base)
{
	long int		len;
	char			*number;
	int				rad;

	rad = ft_strlen(base);
	len = get_len((long int)n, rad);
	if (n == 0)
		if_zero(list);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return ;
	number[len--] = '\0';
	if (n < 0)
	{
		number[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		number[len--] = base[(n % rad)];
		n /= rad;
	}
	ft_print_str_dec(list, number);
	free (number);
}

void	ft_printf_itoa_u(t_print *list, unsigned long long int n, char *base)
{
	unsigned long long int	len;
	char					*number;
	int						rad;

	rad = ft_strlen(base);
	len = get_len_u(n, rad);
	if (n == 0)
		if_zero(list);
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (!number)
		return ;
	number[len--] = '\0';
	if (n < 0)
	{
		number[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		number[len--] = base[(n % rad)];
		n /= rad;
	}
	ft_print_str_dec(list, number);
	free (number);
}

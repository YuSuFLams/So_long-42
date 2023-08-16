/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:43:14 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 02:43:28 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar(char c, int *d)
{
	write(1, &c, 1);
	(*d)++;
}

void	ft_putstr(char *s, int *d)
{
	if (!s)
		ft_putstr("(null)", d);
	else
	{
		while (*s)
		{
			ft_putchar(*s, d);
			s++;
		}
	}
}

void	check_ft_printf(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 'u')
		ft_uputnbr(va_arg(args, unsigned int), len);
	else if (c == 'p')
		ft_upointer(va_arg(args, void *), len, 0);
	else if (c == 'x')
		ft_putlowhex(va_arg(args, unsigned int), len);
	else if (c == 'X')
		ft_putupphex(va_arg(args, unsigned int), len);
	else if (c == '%')
		ft_putchar('%', len);
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = 0;
	if (write(1, 0, 0))
		return (-1);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*str, &i);
		else
		{
			str++;
			check_ft_printf(*str, args, &i);
		}
		str++;
	}
	va_end(args);
	return (i);
}

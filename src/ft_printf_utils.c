/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:44:12 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 02:44:30 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr(int nb, int *d)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-', d);
		n *= (-1);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, d);
		ft_putnbr(n % 10, d);
	}
	else
		ft_putchar(n + 48, d);
}

void	ft_upointer(void *p, int *d, int first)
{
	char			*base;
	unsigned long	n;

	base = "0123456789abcdef";
	n = (unsigned long)p;
	if (first == 0)
		ft_putstr("0x", d);
	if (n >= 16)
	{
		ft_upointer((void *)(n / 16), d, 1);
		ft_putchar(base[n % 16], d);
	}
	else
		ft_putchar(base[n], d);
}

void	ft_putlowhex(unsigned int n, int *d)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		ft_putchar(base[n], d);
	else
	{
		ft_putlowhex(n / 16, d);
		ft_putchar(base[n % 16], d);
	}
}

void	ft_putupphex(unsigned int n, int *d)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(base[n], d);
	else
	{
		ft_putupphex(n / 16, d);
		ft_putchar(base[n % 16], d);
	}
}

void	ft_uputnbr(unsigned int n, int *d)
{
	long	nb;

	nb = n;
	if (nb < 10)
		ft_putchar(n + 48, d);
	else
	{
		ft_uputnbr(nb / 10, d);
		ft_uputnbr(nb % 10, d);
	}
}

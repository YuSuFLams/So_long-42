/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:47:21 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/24 02:31:34 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **str)
{
    if (ac == 1)
	{
		ft_printf("\033[0;36mERROR: \033[0;36mYour Map Should End By (.ber) \"./so_long maps/*.ber)\" !!.\n");
		exit (0);
	}
	if (ac > 2)
	{
		ft_printf("\033[0;36mERROR: \033[0;36mToo Many Args.\n");
		exit (0);
	}
    check_name_map(str[1]);
    check_open_map(str[1]);
    put_map(str[1]);
    return (0);
}
	// system("leaks so_long");
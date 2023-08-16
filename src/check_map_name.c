/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:41:44 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/27 14:09:44 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_name_map(char *map_name)
{
	int	i;

	i = 0;
	while (*(map_name + i) != '.')
		i++;
	if (*(map_name + i) == '.' )
	{
		if (*(map_name + i + 1) != 'b' || *(map_name + i + 2) != 'e' || \
		*(map_name + i + 3) != 'r' || *(map_name + i + 4) != '\0')
		{
			ft_printf("\033[0;36mERROR: \033[0;36mYour Map Should End By ");
			ft_printf("\033[0;36m(.ber) \"./so_long maps/*.ber)\" !!.\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	check_wall_last(char *line)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(line);
	if (len == 1)
	{
		ft_printf("\033[0;35m  Error while checking\n");
		ft_printf("\033[0;35mMap format must be valid\n");
		exit (EXIT_FAILURE);
	}
	while (++i < len)
	{
		if (*(line + i) != '1')
		{
			ft_printf("\033[0;35m  Error while checking\n");
			ft_printf("\033[0;35mMap format must be valid\n");
			exit(EXIT_FAILURE);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:56:49 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/24 02:12:36 by ylamsiah         ###   ########.fr       */
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
			ft_printf("\033[0;36mERROR: \033[0;32mINVALID ARGUMENTS !\n");
			ft_printf("\033[0;31mPlease choose a valid map name.\n");
			exit(EXIT_FAILURE);
		}
	}
}

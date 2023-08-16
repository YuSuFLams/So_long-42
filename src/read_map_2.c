/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:56:04 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/22 18:40:54 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map_2(t_us *vars)
{
	char	**map_dup;
	int		i;
	int		j;

	map_dup = malloc((vars->nbr_line + 1) * sizeof(char *));
	if (!map_dup)
		return (NULL);
	i = -1;
	j = 0;
	while (vars->map[++i])
		map_dup[j++] = ft_strdup(vars->map[i]);
	map_dup[j] = NULL;
	return (map_dup);
}

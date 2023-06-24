/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:16:13 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/24 02:27:03 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	free_map(t_us *vars, char **map)
{
	int	i;

	i = -1;
	while ((++i) < vars->nbr_line)
		free(map[i]);
	free(map);
}

void put_error(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

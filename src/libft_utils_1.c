/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:35:00 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 03:07:43 by ylamsiah         ###   ########.fr       */
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

void put_error(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	free_map(t_us *vars, char **map)
{
	int	i;

	i = -1;
	while ((++i) < vars->nbr_line)
		free(map[i]);
	free(map);
}

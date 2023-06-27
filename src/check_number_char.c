/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:53:40 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 03:30:21 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_line(char *line)
{
	int	i;

	i = 0;
	while (*(line + i) && *(line + i) != '\n')
		i++;
	return (i);
}

int	count_collectible(char *line)
{
	static int	col;
	int			i;

	i = -1;
	while (*(line + (++i)) && *(line + i) != '\n')
		if (*(line + i) == 'C')
			col += 1;
	return (col);
}

int	count_player(char *line)
{
	static int	player;
	int			i;

	i = -1;
	while (*(line + (++i)) && *(line + i) != '\n')
		if (*(line + i) == 'P')
			player += 1;
	return (player);
}

int	count_exit(char *line)
{
	static int	exits;
	int			i;

	i = -1;
	while (*(line + (++i)) && *(line + i) != '\n')
		if (*(line + i) == 'E')
			exits += 1;
	return (exits);
}

int count_col(t_us *game)
{
    int i;
    int j;

    i = -1;
    while (++i < game->nbr_line)
    {
        j = -1;
        while (++j < game->length_line)
        {
            if (game->map[i][j] == 'C')
                game->coins++;
        }
    }
    return (game->coins);
}

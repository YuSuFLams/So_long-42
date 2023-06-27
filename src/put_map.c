/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:56:07 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 05:03:57 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image_in_game(t_us *game)
{	
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/Wall.xpm", &y, &x);
	game->empty = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", \
	&y, &x);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", \
	&y, &x);
	game->col = mlx_xpm_file_to_image(game->mlx, "textures/Coins.xpm", &y, &x);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &y, &x);
}

void	ft_maps(t_us *game, int *y, int *x)
{
	if (game->map[*y][*x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, \
		(*y) * WIDTH_Y, (*x) * HIGHT_X);
	if (game->map[*y][*x] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->empty, \
		(*y) * WIDTH_Y, (*x) * HIGHT_X);
	if (game->map[*y][*x] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, \
		(*y) * WIDTH_Y, (*x) * HIGHT_X);
	if (game->map[*y][*x] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->col, \
		(*y) * WIDTH_Y, (*x) * HIGHT_X);
	if (game->map[*y][*x] == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, \
		(*y) * WIDTH_Y, (*x) * HIGHT_X);
}

void	add_img(t_us *vars)
{
	int	i;
	int	j;

	i = -1;
	while ((++i) < vars->nbr_line)
	{
		j = -1;
		while ((++j) < vars->length_line)
			ft_maps(vars, &i, &j);
	}
}

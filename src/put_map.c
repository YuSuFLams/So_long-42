/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:47:00 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/24 02:35:08 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		while ((++j) < vars->count_line)
			ft_maps(vars, &i, &j);
	}
}

void	put_image_in_game(t_us *game)
{	
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/Wall.xpm", &x, &y);
	game->empty = mlx_xpm_file_to_image(game->mlx, "textures/empty.xpm", \
	&x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", \
	&x, &y);
	game->col = mlx_xpm_file_to_image(game->mlx, "textures/Coins.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &x, &y);
}

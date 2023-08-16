/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:56:07 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/27 14:15:10 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check(char *line, int *ply, int *col, int *ext)
{
	check_map_char(line);
	check_line_map(line);
	*ply = count_player(line);
	*ext = count_exit(line);
	*col = count_collectible(line);
}

static char	*get_image(char img)
{
	char	*image;

	image = NULL;
	if (img == '1')
		image = "textures/Wall.xpm";
	else if (img == '0')
		image = "textures/empty.xpm";
	else if (img == 'P')
		image = "textures/player.xpm";
	else if (img == 'C')
		image = "textures/Coins.xpm";
	else if (img == 'E')
		image = "textures/exit.xpm";
	return (image);
}

void	set_image_in_game(t_us *game, char ch, int x, int y)
{
	void	*p;
	int		a;
	int		b;
	char	*img_path;

	img_path = get_image(ch);
	if (!img_path)
	{
		free_(game);
		perror("Error: Failed to get image path.");
		exit(EXIT_FAILURE);
	}
	p = mlx_xpm_file_to_image(game->mlx, img_path, &a, &b);
	if (!p)
	{
		free_(game);
		perror("\033[0;31mError: The image failed to load.");
		exit(EXIT_FAILURE);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, p, y, x);
	mlx_destroy_image(game->mlx, p);
}

void	add_img(t_us *vars)
{
	int	i;
	int	j;

	i = -1;
	vars->w = 0;
	while (vars->map[++i])
	{
		j = -1;
		vars->h = 0;
		while (vars->map[i][++j])
		{
			if (vars->map[i][j] != '\n')
				set_image_in_game(vars, vars->map[i][j], vars->w, vars->h);
			vars->h += 59;
		}
		vars->w += 59;
	}
}

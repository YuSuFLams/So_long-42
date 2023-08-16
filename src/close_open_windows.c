/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_open_windows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:54:21 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/26 21:24:17 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_all(t_us *game, char *s)
{
	if (ft_strcmp(s, "close") == 0)
		ft_printf("%s", ESH_GAME);
	if (ft_strcmp(s, "good") == 0)
		ft_printf("%s", END_GAME);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_(game);
	exit(EXIT_SUCCESS);
}

int	close_windows(t_us *vars)
{
	free_all(vars, "close");
	exit(EXIT_FAILURE);
}

void	free_(t_us *vars)
{
	free_map(vars);
	free_map_2(vars);
	free(vars);
}

static void	set_err(t_us *vars, char *s)
{
	free_(vars);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	put_error(s);
}

void	set_window(t_us *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		free_(vars);
		put_error("Error: MiniLibX initialization failed.");
		exit(EXIT_FAILURE);
	}
	vars->mlx_win = mlx_new_window(vars->mlx, vars->win_x, vars->win_y, \
	"so_long");
	add_img(vars);
	if (!vars->mlx_win)
	{
		free_(vars);
		set_err(vars, "Error: Cannot create a new window.");
		exit(EXIT_FAILURE);
	}
	if (!mlx_hook(vars->mlx_win, 17, 0, close_windows, vars)) 
		set_err(vars, "Error: Failed to set window close hook.");
	if (!mlx_hook(vars->mlx_win, 2, 0, key_move, vars)) 
		set_err(vars, "Error: Failed to set the key move hook.");
	mlx_loop(vars->mlx);
}

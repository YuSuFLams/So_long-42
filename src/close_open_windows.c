/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_open_windows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:54:21 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 05:11:14 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_windows(t_us *vars)
{
	ft_printf("\033[o;36mYou tab a ESC:\n");
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	free_map(vars, vars->map);
	free(vars);
	exit(0);
}

void	set_window(t_us *vars)
{
	int		win_x;
	int		win_y;

	win_x = vars->length_line * HIGHT_X;
	win_y = vars->nbr_line * WIDTH_Y;
	if (win_y > 1920 || win_x > 1080)
	{
		ft_printf("\033[0;35m\tError\nYour map is so big\n");
		exit(1);
	}
	else
	{
		vars->mlx = mlx_init();
		vars->mlx_win = mlx_new_window(vars->mlx, win_x, win_y, "so_long");
		put_image_in_game(vars);
		add_img(vars);
		mlx_hook(vars->mlx_win, 2, 1L << 0, key_move, vars);
		mlx_hook(vars->mlx_win, 17, 1L << 0, close_windows, vars);
		mlx_loop(vars->mlx);
        free_map(vars, vars->map);
	}
}

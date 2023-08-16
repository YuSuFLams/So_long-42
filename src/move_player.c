/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:56:10 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/27 14:18:03 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_us *vars)
{
	if (vars->map[vars->ply_x][vars->ply_y + 1] == 'C')
	{
		vars->map[vars->ply_x][vars->ply_y] = '0';
		vars->map[vars->ply_x][vars->ply_y + 1] = 'P';
		vars->coins--;
		vars->ply_y++;
		vars->move_count++;
		ft_printf("\033[0;34m[steps] : ==> %d\n", vars->move_count);
	}
	else if (vars->map[vars->ply_x][vars->ply_y + 1] == '0')
	{
		ft_swap(&vars->map[vars->ply_x][vars->ply_y + 1],
			&vars->map[vars->ply_x][vars->ply_y]);
		vars->ply_y++;
		vars->move_count++;
		ft_printf("\033[0;34m[steps] : ==> %d\n", vars->move_count);
	}
	else if (vars->map[vars->ply_x][vars->ply_y + 1] == 'E' && !vars->coins)
		free_all(vars, "good");
	mlx_clear_window(vars->mlx, vars->mlx_win);
}

void	move_left(t_us *vars)
{
	if (vars->map[vars->ply_x][vars->ply_y - 1] == 'C')
	{
		vars->map[vars->ply_x][vars->ply_y] = '0';
		vars->map[vars->ply_x][vars->ply_y - 1] = 'P';
		vars->coins--;
		vars->ply_y--;
		vars->move_count++;
		ft_printf("\033[0;34m[steps] : ==> %d\n", vars->move_count);
	}
	else if (vars->map[vars->ply_x][vars->ply_y - 1] == '0')
	{
		ft_swap(&vars->map[vars->ply_x][vars->ply_y - 1],
			&vars->map[vars->ply_x][vars->ply_y]);
		vars->ply_y--;
		vars->move_count++;
		ft_printf("\033[0;34m[steps] : ==> %d\n", vars->move_count);
	}
	else if (vars->map[vars->ply_x][vars->ply_y - 1] == 'E' && !vars->coins)
		free_all(vars, "good");
	mlx_clear_window(vars->mlx, vars->mlx_win);
}

void	move_up(t_us *vars)
{
	if (vars->map[vars->ply_x - 1][vars->ply_y] == 'C')
	{
		vars->map[vars->ply_x][vars->ply_y] = '0';
		vars->map[vars->ply_x - 1][vars->ply_y] = 'P';
		vars->coins--;
		vars->ply_x--;
		vars->move_count++;
		ft_printf("\033[0;34m[steps] : ==> %d\n", vars->move_count);
	}
	else if (vars->map[vars->ply_x - 1][vars->ply_y] == '0')
	{
		ft_swap(&vars->map[vars->ply_x - 1][vars->ply_y],
			&vars->map[vars->ply_x][vars->ply_y]);
		vars->ply_x--;
		vars->move_count++;
		ft_printf("\033[0;34m[steps] : ==> %d\n", vars->move_count);
	}
	else if (vars->map[vars->ply_x - 1][vars->ply_y] == 'E' && !vars->coins)
		free_all(vars, "good");
	mlx_clear_window(vars->mlx, vars->mlx_win);
}

void	move_down(t_us *vars)
{
	if (vars->map[vars->ply_x + 1][vars->ply_y] == 'C')
	{
		vars->map[vars->ply_x][vars->ply_y] = '0';
		vars->map[vars->ply_x + 1][vars->ply_y] = 'P';
		vars->coins--;
		vars->ply_x++;
		vars->move_count++;
		ft_printf("\033[0;34m[steps] : ==> %d\n", vars->move_count);
	}
	else if (vars->map[vars->ply_x + 1][vars->ply_y] == '0')
	{
		ft_swap(&vars->map[vars->ply_x + 1][vars->ply_y],
			&vars->map[vars->ply_x][vars->ply_y]);
		vars->ply_x++;
		vars->move_count++;
		ft_printf("\033[0;34m[steps] : ==> %d\n", vars->move_count);
	}
	else if (vars->map[vars->ply_x + 1][vars->ply_y] == 'E' && !vars->coins)
		free_all(vars, "good");
	mlx_clear_window(vars->mlx, vars->mlx_win);
}

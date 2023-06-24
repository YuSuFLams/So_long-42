/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 03:21:59 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/24 02:35:29 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_us *vars)
{
	if (vars->map[vars->ply_x][vars->ply_y + 1] != '1')
	{
		vars->move_count++;
	}
	ft_printf("steps : %d\n", vars->move_count);
}

void	move_left(t_us *vars)
{
	// if ()
	// {
		vars->move_count++;
	// }
	ft_printf("steps : %d\n", vars->move_count);
}

void	move_up(t_us *vars)
{
	// if ()
	// {    
		vars->move_count++;
	// }
	ft_printf("steps : %d\n", vars->move_count);
}

void	move_down(t_us *vars)
{
	// if ()
	// {
		vars->move_count++;
	// }
	ft_printf("steps : %d\n", vars->move_count);
}


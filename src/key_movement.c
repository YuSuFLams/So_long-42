/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:56:15 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/24 15:44:32 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_move(int key, t_us *vars)
{
	if (key == 0 || key == 123)
		move_left(vars);
	if (key == 1 || key == 125)
		move_down(vars);
	if (key == 2 || key == 124)
		move_right(vars);
	if (key == 13 || key == 126)
		move_up(vars);
	if (key == 53)
		close_windows(vars);
	add_img(vars);
	return (0);
}

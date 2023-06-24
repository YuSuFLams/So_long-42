/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:38:58 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/24 02:38:59 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void valid_all_path(t_us *game, int i, int j)
{
    if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
		game->cn_ex++;
	if (game->map[i - 1][j] != '1')
	{
		game->map[i - 1][j] = '1';
		valid_all_path(game, i - 1, j);
	}
	if (game->map[i][j - 1] != '1')
	{
		game->map[i][j - 1] = '1';
		valid_all_path(game, i, j - 1);
	}
	if (game->map[i + 1][j] != '1')
	{
		game->map[i + 1][j] = '1';
		valid_all_path(game, i + 1, j);
	}
	if (game->map[i][j + 1] != '1')
	{
		game->map[i][j + 1] = '1';
		valid_all_path(game, i, j + 1);
	}
}

void test_game(t_us *game)
{
    count_col(game);
    valid_all_path(game, game->ply_y, game->ply_x);
    if (game->col + 1 != game->cn_ex)
    {
        free_map(game,game->map);
        put_error("\033[0;36mMust Be Valid Path\n");
    }
    printf("\ncol/ext-1 = %d\n",game->cn_ex);
    printf("\ncol/ext = %d\n",game->col);
    printf("\nx = %d\ny = %d\n",game->ply_x, game->ply_y);

}

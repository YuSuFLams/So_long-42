/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:54:57 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/26 18:37:19 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_pos_exit(t_us *game)
{
	char	**str;
	int		i;
	int		j;

	str = game->map;
	i = -1;
	while (++i < game->nbr_line)
	{
		j = -1;
		while (++j < game->length_line)
		{
			if (str[i][j] == 'E')
			{
				game->exit_x = i;
				game->exit_y = j;
			}
		}
	}
}

int	count_ex_col(t_us *game)
{
	int	col_ex;
	int	i;
	int	j;

	col_ex = 0;
	i = -1;
	while (++i < game->nbr_line)
	{
		j = -1;
		while (++j < game->length_line)
		{
			if (game->map_2[i][j] == 'C')
				col_ex++;
		}
	}
	return (col_ex);
}

void	valid_all_path(t_us *game, int i, int j)
{
	if (game->map_2[i - 1][j] == 'C' || game->map_2[i - 1][j] == '0')
	{
		game->map_2[i - 1][j] = 'P';
		valid_all_path(game, i - 1, j);
	}
	if (game->map_2[i][j - 1] == 'C' || game->map_2[i][j - 1] == '0')
	{
		game->map_2[i][j - 1] = 'P';
		valid_all_path(game, i, j - 1);
	}
	if (game->map_2[i + 1][j] == 'C' || game->map_2[i + 1][j] == '0')
	{
		game->map_2[i + 1][j] = 'P';
		valid_all_path(game, i + 1, j);
	}
	if (game->map_2[i][j + 1] == 'C' || game->map_2[i][j + 1] == '0')
	{
		game->map_2[i][j + 1] = 'P';
		valid_all_path(game, i, j + 1);
	}
}

int	check_ext(t_us *game)
{
	if (game->map_2[game->exit_x][game->exit_y - 1] == 'P')
		return (0);
	if (game->map_2[game->exit_x][game->exit_y + 1] == 'P')
		return (0);
	if (game->map_2[game->exit_x - 1][game->exit_y] == 'P')
		return (0);
	if (game->map_2[game->exit_x + 1][game->exit_y] == 'P')
		return (0);
	else
		return (1);
}

void	test_game(t_us *game)
{
	int	col_ex;

	game->move_count = 0;
	valid_all_path(game, game->ply_x, game->ply_y);
	col_ex = count_ex_col(game);
	if (col_ex || check_ext(game))
	{
		free_(game);
		ft_printf("\033[0;36mMust Be Valid Path\n");
		exit(EXIT_FAILURE);
	}
}

#include "so_long.h"

void	move_right(t_us *vars)
{
	if (vars->map[vars->ply_y][vars->ply_y + 1] != '1')
	{
		vars->move_count++;
	}
	ft_printf("steps : %d\n", vars->move_count);
}

void	move_left(t_us *vars)
{
	if ()
	{
		vars->move_count++;
	}
	ft_printf("steps : %d\n", vars->move_count);
}

void	move_up(t_us *vars)
{
	if ()
	{    
		vars->move_count++;
	}
	ft_printf("steps : %d\n", vars->move_count);
}

void	move_down(t_us *vars)
{
	if ()
	{
		vars->move_count++;
	}
	ft_printf("steps : %d\n", vars->move_count);
}







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
}

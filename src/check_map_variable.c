/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:56:29 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/27 14:09:25 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_sides_wall(char *line)
{
	int	j;

	j = ft_strlen(line) - 2;
	if (*line != '1' || *(line + j) != '1')
	{
		ft_printf("\033[0;36m       Error checking sidewalls \n");
		ft_printf("\033[0;36mYour map should start and end sides by 1\n");
		exit(EXIT_FAILURE);
	}
}

void	check_map_char(char *line)
{
	int	i;

	i = -1;
	while (*(line + (++i)) && *(line + i) != '\n')
	{
		if (*(line + i) != '1' && *(line + i) != '0' && *(line + i) != 'E' && \
		*(line + i) != 'P' && *(line + i) != 'C')
		{
			ft_printf("\033[0;36m\t    ERROR\nMap Contains Other Characters\n");
			exit (EXIT_FAILURE);
		}
	}
}

void	check_wall_first(char *line)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(line);
	if (len == 1)
	{
		ft_printf("\033[0;35m  Error while checking\n");
		ft_printf("\033[0;35mMap format must be valid\n");
		exit (EXIT_FAILURE);
	}
	while (++i < len - 1)
	{
		if (*(line + i) != '1')
		{
			ft_printf("\033[1;36m\t\t\b\bERROR\n");
			ft_printf("\033[1;36mYour map is not surrounded by a wall.\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	check_line_map(char *line)
{
	static int	count;

	if (!count)
		count = count_line(line);
	else if (count != count_line(line))
	{
		ft_printf("\033[0;35m  Error while checking\n");
		ft_printf("\033[0;35mMap format must be valid\n");
		exit(EXIT_FAILURE);
	}
}

void	check_pos_player(t_us *game)
{
	char	**str;
	int		i;
	int		j;

	game->coins = count_col(game);
	str = game->map;
	i = -1;
	while (++i < game->nbr_line)
	{
		j = -1;
		while (++j < game->length_line)
		{
			if (str[i][j] == 'P')
			{
				game->ply_x = i;
				game->ply_y = j;
			}
		}
	}
}

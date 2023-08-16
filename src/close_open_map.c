/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_open_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:56:25 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/27 14:09:04 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_error(int col, int ply, int ext)
{
	if (!col || !ext || !ply || ply > 1 || ext > 1)
	{
		if (!ext || ext > 1)
		{
			ft_printf("\033[0;36mERROR: ");
			ft_printf("\033[0;32mYour map does not contain a only one exit.\n");
		}
		if (!col)
		{
			ft_printf("\033[0;36mERROR: ");
			ft_printf("\033[0;32mYour map does not contain a collectible.\n");
		}
		if (!ply || ply >= 2)
		{
			ft_printf("\033[0;36mERROR: ");
			ft_printf("\033[0;32mYour map does not contain a only one player.\n");
		}
		exit(EXIT_FAILURE);
	}
}

void	check_map_ec(int fd, int *size_map)
{
	char			*line;
	char			*s;
	static int		ply;
	static int		ext;
	static int		col;

	s = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		*size_map = ft_strlen(line) + 1;
		if (!s)
			check_wall_first(line);
		else
			check_sides_wall(line);
		check(line, &ply, &col, &ext);
		free(s);
		s = line;
	}
	check_error(col, ply, ext);
	check_wall_last(s);
	free(s);
}

void	check_open_map(char *str)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		put_error("\033[0;35mopen");
	}
	else
	{
		check_map_ec(fd, &i);
		if (close(fd) != 0)
		{
			put_error("\033[0;35mclose");
		}
	}
}

static void	check_win(t_us *vars)
{
	vars->map_2 = read_map_2(vars);
	if (vars->map_2 == NULL) 
	{
		free_map(vars);
		free(vars);
		exit(EXIT_FAILURE);
	}
	check_pos_exit(vars);
	check_pos_player(vars);
	test_game(vars);
	vars->win_x = vars->length_line * HIGHT_X;
	vars->win_y = vars->nbr_line * WIDTH_Y;
	if (vars->win_y > 1475 || vars->win_x > 2537)
	{
		ft_printf("\033[0;35m\tError\nYour map is so big\n");
		exit(1);
	}
}

void	put_map(char *file)
{
	int		j;
	t_us	*vars;

	j = 0;
	vars = (t_us *)malloc(sizeof(t_us));
	if (!vars) 
	{
		perror("Error: Memory allocation failed.");
		exit(EXIT_FAILURE);
	}
	vars->map = read_map(file, j, vars);
	if (!vars->map) 
	{
		free(vars);
		exit(EXIT_FAILURE);
	}
	check_win(vars);
	set_window(vars);
}

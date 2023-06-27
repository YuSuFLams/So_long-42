/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_open_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:56:25 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 04:34:00 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check(char *line, int *ply, int *col, int *ext)
{
	check_map_char(line);
	check_line_map(line);
	*ply = count_player(line);
	*ext = count_exit(line);
	*col = count_collectible(line);
}

void	check_error(int col, int ply, int ext)
{
	if (!col || !ext || !ply || ply > 1 || ext > 1)
	{
		if (!ext || ext > 1)
			ft_printf("\033[0;36mERROR: \033[0;32mYour map does not contain a only one exit.\n");
		if (!col)
			ft_printf("\033[0;36mERROR: \033[0;32mYour map does not contain a collectible.\n");
		if (!ply || ply >= 2)
			ft_printf("\033[0;36mERROR: \033[0;32mYour map does not contain a only one player.\n");
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
			check_wall_fl(line);
		else
			check_sides_wall(line);
		check(line, &ply, &col, &ext);
		free(s);
		s = line;
	}
	check_error(col, ply, ext);
	check_wall_fl(s);
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
			put_error("close");
		}
	}
}

void	put_map(char *file)
{
	int		fd;
	int 	j;
	t_us	*vars;

	j = 0;
	vars = (t_us *)malloc(sizeof(t_us));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	vars->map = read_map(file, j, vars);
	if (!vars->map)
		return ;
	check_pos_player(vars);
	set_window(vars);
	if (close(fd) != 0)
	{
		put_error("\e[0;mclose");
    }
}

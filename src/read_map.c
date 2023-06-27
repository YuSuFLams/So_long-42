/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:56:04 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/06/27 03:26:11 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**read_map(char *file, int i, t_us *vars)
{
	int		fd;
	char	*line;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
    {
        put_error("\033[0;36mopen");
    }
    while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		vars->length_line = count_line(line);
		i++;
		str = ft_strjoin(str, line);
		free(line);
	}
	vars->nbr_line = i;
    if (close(fd) != 0)
    {
        put_error("\033[0;36merror");
    }
	return (ft_split(str, '\n'));
}

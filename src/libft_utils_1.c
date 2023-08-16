/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:35:00 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/26 18:30:41 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	put_error(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

void	free_map(t_us *vars)
{
	int	i;

	i = -1;
	while ((++i) < vars->nbr_line)
		free(vars->map[i]);
	free(vars->map);
}

void	free_map_2(t_us *vars)
{
	int	i;

	i = -1;
	while ((++i) < vars->nbr_line)
		free(vars->map_2[i]);
	free(vars->map_2);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)) && *(s1 + i) == *(s2 + i))
		i++;
	return (*(s1 + i) - *(s2 + i));
}

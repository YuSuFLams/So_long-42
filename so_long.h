/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 02:27:24 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/07/27 14:21:51 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>

# define END_GAME "\033[0;36mCongratulation You Finished The Game \
-->** BRAVO **<--\n"
# define ESH_GAME "\033[0;36mYou Tab A ESC:\n"

# define HIGHT_X	59
# define WIDTH_Y	59

//open_map

typedef struct s_us
{
	void	*mlx;
	void	*mlx_win;
	char	*line;
	char	**map;
	char	**map_2;
	int		length_line;
	int		nbr_line;
	int		move_count;
	int		ply_y;
	int		ply_x;
	int		exit_x;
	int		exit_y;
	int		cl_ex;
	int		coins;
	int		w;
	int		h;
	int		win_x;
	int		win_y;
}	t_us;

// get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*set_read_line(char *line);
char	*ft_strchr(char *s, int c);
char	*set_next_line(char *line);
char	*read_line(int fd, char *line);
char	*ft_strjoin(char *s1, char *s2);

//src_ft_printf
void	ft_putnbr(int nb, int *d);
void	ft_putchar(char c, int *d);
void	ft_putstr(char *s, int *d);
int		ft_printf(const char *str, ...);
void	ft_uputnbr(unsigned int n, int *d);
void	ft_putlowhex(unsigned int n, int *d);
void	ft_putupphex(unsigned int n, int *d);
void	ft_upointer(void *p, int *d, int first);
void	check_ft_printf(char c, va_list args, int *len);

//src_libft
int		ft_strlen(const char *s);
void	ft_swap(char *a, char *b);
void	freesplit(char **s, int i);
char	*ft_strdup(const char *src);
int		count(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);

//function so_long
void	check_line_map(char *line);
void	check_map_char(char *line);
void	check_wall_last(char *line);
void	check_pos_player(t_us *game);
void	check_wall_first(char *line);
void	check_sides_wall(char *line);
void	check_name_map(char *map_name);

int		count_col(t_us *game);
int		count_exit(char *line);
int		count_line(char *line);
int		count_player(char *line);
int		count_collectible(char *line);

void	put_error(char *s);
void	put_map(char *file);
void	free_map_2(t_us *vars);
char	**read_map_2(t_us *vars);
void	check_open_map(char *str);
void	check_map_ec(int fd, int *size_map);
void	check_error(int col, int ply, int ext);
char	**read_map(char *file, int i, t_us *vars);
void	check(char *line, int *ply, int *col, int *ext);

//movement_player
void	move_up(t_us *vars);
void	move_left(t_us *vars);
void	move_down(t_us *vars);
void	move_right(t_us *vars);
int		key_move(int key, t_us *vars);

//put_windows
void	add_img(t_us *vars);
void	free_map(t_us *vars);
void	set_window(t_us *vars);
int		close_windows(t_us *vars);

void	free_(t_us *vars);
void	test_game(t_us *game);
int		count_ex_col(t_us *game);
void	check_pos_exit(t_us *game);
void	free_all(t_us *game, char *s);
void	valid_all_path(t_us *game, int i, int j);
void	set_image_in_game(t_us *vars, char c, int i, int j);


#endif
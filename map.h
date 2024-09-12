#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "./getnextline/get_next_line.h"
#include "libft/libft.h"

typedef struct s_map
{
	char	**map;
	char	*map_line;
	int		x;
	int		y;
	int		x_len;
	int		y_len;
	int		player_pos;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}t_map;

int		parse_infos(int fd, t_map *infos);
int 	check_infos(t_map *infos, char **first_half);
int		check_textures(t_map *infos);
int		check_rgb(t_map *map);
char	**get_infos(int fd, t_map *infos);
char	*ft_datacpy(char *src, int n);
int		is_empty_line(char *str);
int 	only_ones(char *str);
char	*ft_strcpy(char *src);
void	free_arr(char **arr);
void	free_data(t_map *data);
char	**get_map(int fd, t_map *infos);
// int		not_valid(char c);
// int		is_there(char *str, char c);

#endif
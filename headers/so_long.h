/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:15:54 by prossi            #+#    #+#             */
/*   Updated: 2025/01/25 16:20:17 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../headers/get_next_line.h"
# include "../headers/libft.h"
# include "../headers/ft_printf.h"
# include <mlx.h>

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		columncount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;
	char	**mapcopy;

	void	*floor;
	void	*barrier;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int		exit_point(t_complete *game);
int		read_map(t_complete *game, char **argv);
int		move_player(int command, t_complete *game);
void	ft_add_in_graphics(t_complete *game);
void	ft_put_images_in_game(t_complete *game);
void	ft_check_errors(t_complete *game);
int		check_horizontalwall(t_complete *game);
int		check_verticalwall(t_complete *game);
void	check_walls(t_complete *game);
void	count_caracters(t_complete *game, int height, int width);
void	ft_character_valid(t_complete *game);
void	ft_to_fill(t_complete *game, int move_x, int move_y);
void	ft_player_position(t_complete *game, int *pl_row, int *pl_colun);
void	copy_map(t_complete *game);
void	free_mapcopy(t_complete *game);
void	render_movement_count(t_complete *game);
char	*ft_itoa(int n);
void	check_is_rectangular(t_complete *game);
void	flood_fill(t_complete *game, int move_x, int move_y);
int		ft_ajouter_ligne_map(t_complete *game, char *line);
void	ft_free_images(t_complete *game);
void	init_struct(t_complete *game);
void	player_in_map(t_complete *game, int height, int width);
void	collectable_in_map(t_complete *game, int height, int width);
int		ft_largeur_map(char *string);
int		check_ber_extension(const char *filename);
int		ft_exit(t_complete *game);

#endif

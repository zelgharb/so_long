/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:57:36 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/27 22:06:12 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	exit_point(t_complete *game)
{
	int	line;

	line = 0;
	ft_free_images(game);
	if (game->mlxpointer)
	{
		if (game->winpointer)
			mlx_destroy_window(game->mlxpointer, game->winpointer);
		mlx_destroy_display(game->mlxpointer);
		free(game->mlxpointer);
		game->mlxpointer = NULL;
	}
	if (game->map)
	{
		while (line < game->heightmap)
			free(game->map[line++]);
		free(game->map);
		game->map = NULL;
	}
	if (game->mapcopy)
		free_mapcopy(game);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	init_struct(&game);
	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_complete));
	if (read_map(&game, argv) == 0)
		exit_point(&game);
	ft_check_errors(&game);
	game.mlxpointer = mlx_init();
	if (!game.mlxpointer)
		exit_point(&game);
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 50),
			(game.heightmap * 50), "solong");
	if (!game.widthmap)
		exit_point(&game);
	ft_put_images_in_game(&game);
	ft_add_in_graphics(&game);
	mlx_key_hook(game.winpointer, move_player, &game);
	mlx_hook(game.winpointer, 17, 0, exit_point, &game);
	mlx_loop(game.mlxpointer);
	return (0);
}

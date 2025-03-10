/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_in_graphics.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:26:24 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/24 16:26:34 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/so_long.h"

static void	put_image(t_complete *game, int height, int width, char symbol)
{
	if (symbol == '1')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->barrier, width * 50, height * 50);
	else if (symbol == 'C')
		collectable_in_map(game, height, width);
	else if (symbol == 'P')
		player_in_map(game, height, width);
	else if (symbol == 'E')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->exit, width * 50, height * 50);
	else if (symbol == '0')
		mlx_put_image_to_window(game->mlxpointer,
			game->winpointer, game->floor, width * 50, height * 50);
}

void	ft_add_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			put_image(game, height, width, game->map[height][width]);
			width++;
		}
		height++;
	}
}

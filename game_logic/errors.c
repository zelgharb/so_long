/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:49:37 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/25 16:28:18 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_horizontalwall(t_complete *game)
{
	int	i;
	int	j;

	i = game->widthmap;
	j = 0;
	while (j < i)
	{
		if (!(game->map[0][j] == '1'
			&& game->map[game->heightmap - 1][j] == '1'))
			return (0);
		j++;
	}
	return (1);
}

int	check_verticalwall(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

void	check_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	check_is_rectangular(game);
	verticalwalls = check_verticalwall(game);
	horizontalwalls = check_horizontalwall(game);
	if (!verticalwalls)
	{
		ft_printf("\nError\n Vertical walls are missing\n");
		exit_point(game);
	}
	if (!horizontalwalls)
	{
		ft_printf("\nError\n Horizontal walls are missing\n");
		exit_point(game);
	}
}

void	count_caracters(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("Error\nthe caracter is not valid\n%c\n");
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->columncount++;
	if (game->map[height][width] == 'P')
		game->playercount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	ft_character_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_caracters(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->columncount >= 1
			&& game->exitcount == 1))
	{
		ft_printf("Error\nEither player, exit or collectable issue\n");
		exit_point(game);
	}
}

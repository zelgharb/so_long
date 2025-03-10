/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_rectangular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:35:34 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/21 01:39:27 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/so_long.h"

void	check_is_rectangular(t_complete *game)
{
	int	y_map;
	int	x_map;
	int	backup;

	y_map = 0;
	backup = 0;
	while (y_map < game->heightmap)
	{
		x_map = 0;
		while (game->map[y_map][x_map] != '\0')
			x_map++;
		if (backup != 0)
		{
			if (backup != x_map)
			{
				ft_printf("ERROR\n The map is not rectangular.\n");
				exit_point(game);
			}
		}
		else
			backup = x_map;
		y_map++;
	}
}

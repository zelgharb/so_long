/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:44:40 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/24 18:49:48 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/so_long.h"

void	flood_fill(t_complete *game, int move_x, int move_y)
{
	if (move_x < 0 || move_y < 0 || move_x >= game->heightmap
		|| move_y >= game->widthmap || game->mapcopy[move_x][move_y] == '1'
			|| game->mapcopy[move_x][move_y] == 'X')
		return ;
	if (game->mapcopy[move_x][move_y] == 'C')
		game->mapcopy[move_x][move_y] = 'X';
	if (game->mapcopy[move_x][move_y] == 'E')
	{
		game->mapcopy[move_x][move_y] = 'X';
		return ;
	}
	game->mapcopy[move_x][move_y] = 'X';
	flood_fill(game, move_x - 1, move_y);
	flood_fill(game, move_x + 1, move_y);
	flood_fill(game, move_x, move_y - 1);
	flood_fill(game, move_x, move_y + 1);
}

void	ft_player_position(t_complete *game, int *pl_row, int *pl_colun)
{
	int	i;
	int	j;

	i = 0;
	while (game->mapcopy[i])
	{
		j = 0;
		while (game->mapcopy[i][j])
		{
			if (game->mapcopy[i][j] == 'P')
			{
				*pl_row = i;
				*pl_colun = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	copy_map(t_complete *game)
{
	int	i;

	i = 0;
	game->mapcopy = malloc(sizeof(char *) * (game->heightmap + 1));
	if (!game->mapcopy)
	{
		ft_printf("Error\nError allocating memory for mapcopy\n");
		exit(1);
	}
	while (i < game->heightmap)
	{
		game->mapcopy[i] = ft_strdup(game->map[i]);
		if (!game->mapcopy[i])
		{
			ft_printf("Error\nError copying map row %d\n", i);
			exit(1);
		}
		i++;
	}
	game->mapcopy[i] = NULL;
}

void	free_mapcopy(t_complete *game)
{
	int	i;

	if (game->mapcopy)
	{
		i = 0;
		while (i < game->heightmap)
		{
			if (game->mapcopy[i])
				free(game->mapcopy[i]);
			i++;
		}
		free(game->mapcopy);
		game->mapcopy = NULL;
	}
}

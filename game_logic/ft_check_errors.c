/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:53:59 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/25 16:21:07 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/so_long.h"

static void	ft_validate_map(t_complete *game, int *pl_row, int *pl_colun)
{
	check_walls(game);
	ft_character_valid(game);
	copy_map(game);
	ft_player_position(game, pl_row, pl_colun);
	flood_fill(game, *pl_row, *pl_colun);
}

static void	ft_check_collectibles_and_exit(t_complete *game)
{
	int	can_row;
	int	can_colun;

	can_row = 0;
	while (game->mapcopy[can_row])
	{
		can_colun = 0;
		while (game->mapcopy[can_row][can_colun])
		{
			if (game->mapcopy[can_row][can_colun] == 'C'
				|| game->mapcopy[can_row][can_colun] == 'E')
			{
				ft_printf("Error\nThere is no possible way to win\n");
				exit_point(game);
			}
			can_colun++;
		}
		can_row++;
	}
}

void	ft_check_errors(t_complete *game)
{
	int	pl_row;
	int	pl_colun;

	pl_row = 0;
	pl_colun = 0;
	ft_validate_map(game, &pl_row, &pl_colun);
	ft_check_collectibles_and_exit(game);
	free_mapcopy(game);
}

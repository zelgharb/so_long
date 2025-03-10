/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:35:20 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/24 16:35:29 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/so_long.h"

void	init_struct(t_complete *game)
{
	if (!game)
		return ;
	game->fd = 0;
	game->heightmap = 0;
	game->widthmap = 0;
	game->playercount = 0;
	game->columncount = 0;
	game->exitcount = 0;
	game->x_axis = 0;
	game->y_axis = 0;
	game->counter = 0;
	game->collectables = 0;
	game->map = NULL;
	game->mapcopy = NULL;
	game->floor = NULL;
	game->barrier = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->collectable = NULL;
	game->mlxpointer = NULL;
	game->winpointer = NULL;
}

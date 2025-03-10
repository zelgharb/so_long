/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:41:30 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/24 22:20:10 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	moving(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E' )
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\nYou Have Won, Congrats!\n");
		exit_point(game);
	}
	if (game->map[j][i] == '0' || game->map[j][i] == 'C')
	{
		if (game->map[j][i] == 'C')
			game->collectables--;
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	return (1);
}

static int	vertical_move(t_complete *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 119)
		j--;
	else if (movement == 115)
		j++;
	else
		return (0);
	if (game->map[j][i] == '1')
		return (0);
	if (!moving(game, i, j))
		return (0);
	if (movement == 119)
		game->map[j + 1][i] = '0';
	else
		game->map[j - 1][i] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	return (1);
}

static int	horizontal_move(t_complete *game, int movement)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	if (movement == 97)
		i--;
	else if (movement == 100)
		i++;
	else
		return (0);
	if (game->map[j][i] == '1')
		return (0);
	if (!moving(game, i, j))
		return (0);
	if (movement == 97)
		game->map[j][i + 1] = '0';
	else
		game->map[j][i - 1] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	return (1);
}

int	move_player(int command, t_complete *game)
{
	int	works;

	if (command == 65307)
		exit_point(game);
	if (command == 119)
		works = vertical_move(game, command);
	if (command == 115)
		works = vertical_move(game, command);
	if (command == 97)
		works = horizontal_move(game, command);
	if (command == 100)
		works = horizontal_move(game, command);
	if (works)
		ft_add_in_graphics(game);
	return (1);
}

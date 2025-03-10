/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:31:04 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/24 16:31:12 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/so_long.h"

static int	ft_lire_lignes_map(t_complete *game)
{
	char	*readmap;

	readmap = get_next_line(game->fd);
	while (readmap)
	{
		if (!ft_ajouter_ligne_map(game, readmap))
		{
			free(readmap);
			return (0);
		}
		readmap = get_next_line(game->fd);
	}
	return (1);
}

int	read_map(t_complete *game, char **argv)
{
	if (!check_ber_extension(argv[1]))
	{
		ft_printf("Error\n File must have a .ber extension.\n");
		return (0);
	}
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	game->heightmap = 0;
	game->map = NULL;
	if (!ft_lire_lignes_map(game))
		return (0);
	if (game->heightmap > 0)
		game->widthmap = ft_largeur_map(game->map[0]);
	if (game->widthmap > 300 || game->heightmap > 200)
	{
		ft_printf("Error\nThe map width or height is long!");
		return (0);
	}
	close(game->fd);
	return (1);
}

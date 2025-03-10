/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 01:28:09 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/24 16:30:24 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_largeur_map(char *string)
{
	int	width;

	width = 0;
	if (!string)
		return (0);
	while (string[width] != '\0')
		width++;
	if (width > 0 && string[width - 1] == '\n')
		width--;
	return (width);
}

int	ft_ajouter_ligne_map(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	temporary = malloc(sizeof(char *) * (game->heightmap + 2));
	if (!temporary)
	{
		free(line);
		return (0);
	}
	i = -1;
	while (++i < game->heightmap)
		temporary[i] = game->map[i];
	temporary[i] = ft_strdup(line);
	temporary[i + 1] = NULL;
	free(line);
	free(game->map);
	game->map = temporary;
	game->heightmap++;
	return (1);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	check_ber_extension(const char *filename)
{
	size_t	len;

	len = strlen(filename);
	if (len >= 4 && ft_strcmp(filename + len - 4, ".ber") == 0)
		return (1);
	return (0);
}

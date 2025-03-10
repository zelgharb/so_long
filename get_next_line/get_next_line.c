/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:25:51 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/21 02:02:58 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/get_next_line.h"

static char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

static char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

static char	*ft_line(char *buffer)
{
	int		i;
	char	*mem;

	i = 0;
	if (!buffer[i])
	{
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	mem = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		mem[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		mem[i++] = '\n';
	return (mem);
}

static char	*ft_read(int fd, char *resultat)
{
	char			*buffer;
	ssize_t			number_read;

	if (!resultat)
		resultat = ft_calloc(1, 1);
	buffer = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	number_read = 1;
	while (number_read > 0)
	{
		number_read = read(fd, buffer, BUFFER_SIZE);
		if (number_read == -1)
		{
			free(buffer);
			free(resultat);
			return (NULL);
		}
		buffer[number_read] = '\0';
		resultat = ft_free(resultat, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (resultat);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
/*int main(void)
 {
     int fd;
     char *line;

     fd = open("test.txt", O_RDONLY);
     if (fd == -1)
     {
         printf("Erreur d'ouverture du fichier.\n");
         return (1);
     }
     while ((line = get_next_line(fd)) != NULL)
     {
         printf("%s", line);
         free(line);
     }
     close(fd);
     return (0);
}*/

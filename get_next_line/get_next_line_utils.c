/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:26:26 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/24 18:55:34 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		slen;
	char	*mem;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	slen = ft_strlen(s1) + ft_strlen(s2);
	mem = (char *)malloc(sizeof(char) * (slen + 1));
	if (!mem)
	{
		return (0);
	}
	while (s1[i] != '\0')
	{
		mem[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		mem[i++] = s2[j++];
	mem[i] = '\0';
	return (mem);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*result;

	result = (char *)s;
	i = 0;
	while (result[i] != '\0')
	{
		if (result[i] == (char)c)
			return (result + i);
		i++;
	}
	if ((char)c == '\0')
		return (result + i);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (nmemb != 0 && (SIZE_MAX / nmemb) < size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:07:59 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/20 23:24:34 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	if (str == NULL)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, len);
		str++;
	}
}
/*int main()
{
	int count = 0;
	char str[] = "QWERTYUIO";
	ft_putstr(str, &count);
	ft_printf("\n%d", count);
	printf("\n%d", count);
}*/

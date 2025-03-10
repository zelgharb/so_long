/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:34:05 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/20 23:24:19 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char Xx, int *len)
{
	unsigned int	hex_len;
	char			*base;

	hex_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < hex_len)
		ft_putchar(base[nbr % hex_len], len);
	else
	{
		ft_putnbr_base(nbr / hex_len, Xx, len);
		ft_putnbr_base(nbr % hex_len, Xx, len);
	}
}
/*int main()
{
	int len = 0;
	int a = -2147483648;
	// int *ptr = &a;
	ft_putnbr_base(a, 'x', &len);
	ft_printf("\n%d",len);
	printf("\n%d",len);
}*/

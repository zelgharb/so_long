/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:30:29 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/20 23:24:08 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	putnbr_base1(unsigned long nbr, char Xx, int *len)
{
	unsigned long	hex_len;
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
		putnbr_base1(nbr / hex_len, Xx, len);
		putnbr_base1(nbr % hex_len, Xx, len);
	}
}

void	ft_putaddr(void *addr, int *len)
{
	unsigned long	str;

	if (addr == NULL)
	{
		ft_putstr("0x0", len);
		return ;
	}
	str = (unsigned long)addr;
	ft_putstr("0x", len);
	putnbr_base1(str, 'x', len);
}
/*int main()
{
	int len = 0;
	int a = 99;
	int *ptr = &a;
	ft_putaddr(ptr, &len);
	ft_printf("\n%d",len);
	printf("\n%d",len);
}*/

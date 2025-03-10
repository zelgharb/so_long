/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:03:50 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/20 23:24:27 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', len);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, len);
		ft_putnbr((nbr % 10), len);
	}
	else
		ft_putchar((nbr + '0'), len);
}
/*int main()
{
	int len = 0;
	int a = -2147483648;
	ft_putnbr(a, &len);
	ft_printf("\n%d",len);
	printf("\n%d",len);
}*/

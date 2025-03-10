/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:06:37 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/20 23:24:23 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *len)
{
	if (n >= 10)
	{
		ft_putnbr_u(n / 10, len);
		ft_putnbr_u(n % 10, len);
	}
	else
		ft_putchar(n + '0', len);
}
/*int main()
{
	int len = 0;
	int a = -2147483648;
	ft_putnbr_u(a, &len);
	ft_printf("\n%d",len);
	printf("\n%d",len);
}*/

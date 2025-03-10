/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgarb <zelgarb@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:13:35 by zelgharb          #+#    #+#             */
/*   Updated: 2024/11/21 23:44:42 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *Format, ...);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putchar(char c, int *len);
void	ft_putnbr_u(unsigned int n, int *len);
void	ft_putaddr(void *addr, int *len);
void	ft_putnbr_base(unsigned int nbr, char Xx, int *len);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelgharb <zelgharb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:56:45 by zelgharb          #+#    #+#             */
/*   Updated: 2025/01/20 23:23:55 by zelgharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	ft_check_flags(va_list list, const char format, int *len)
{
	if (!format)
		return (-3);
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(list, int), len);
	else if (format == 'u')
		ft_putnbr_u(va_arg(list, unsigned int), len);
	else if (format == 'c')
		ft_putchar((char)va_arg(list, int), len);
	else if (format == 's')
		ft_putstr(va_arg(list, char *), len);
	else if (format == '%')
		ft_putchar(format, len);
	else if (format == 'x')
		ft_putnbr_base(va_arg(list, unsigned int), format, len);
	else if (format == 'X')
		ft_putnbr_base(va_arg(list, unsigned int), format, len);
	else if (format == 'p')
		ft_putaddr(va_arg(list, void *), len);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		len;
	int		n;

	len = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			n = ft_check_flags(list, *format, &len);
			if (n == -3)
				return (len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(list);
	return (len);
}
/*int main()
{
	char str[] = "NULL";
	int x = 9999;
	int *ptr = &x;
	ft_printf("%s\n",str);
	printf("%s\n",str);
	ft_printf("ft_printf: String: %s\n", "Hello");
    printf("Expected: Hello\n");
	ft_printf("ft_printf: Integer: %d\n", -123);
    printf("Expected: -123\n");
	ft_printf("ft_printf:  %p\n", "99");
    printf("Expected: %p\n", "99");
	ft_printf("ft_printf:  %i\n", 999);
    printf("Expected: %i\n", 999);
	ft_printf("ft_printf:  %c\n", 'q');
    printf("Expected: %c\n", 'q');
	ft_printf("ft_printf:  %u\n", -999);
    printf("Expected: %u\n", -999);
	ft_printf("ft_printf:  %u\n", 999);
    printf("Expected: %u\n", 999);
	ft_printf("ft_printf:  %x\n", -999);
    printf("Expected: %x\n", -999);
	ft_printf("ft_printf:  %X\n", -999);
    printf("Expected: %X\n", -999);
	ft_printf("ft_printf:  %p\n", ptr);
	printf("%d",printf("%s",NULL));
}
int main()
{
	printf("\n%d\n", ft_printf("%k"));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:24:16 by ttinnerh          #+#    #+#             */
/*   Updated: 2023/10/09 22:04:39 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check_format(char spec, va_list ap)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += putchar(va_arg(ap, int));
	else if (spec == 's')
		count += putstr(va_arg(ap, char *));
	else if (spec == 'p')
		count += print_pointer(va_arg(ap, unsigned long));
	else if (spec == 'd' || spec == 'i')
		count += print_digit(va_arg(ap, int));
	else if (spec == 'u')
		count += print_digit(va_arg(ap, unsigned int));
	else if (spec == 'x')
		count += print_hex(va_arg(ap, unsigned int), 'x');
	else if (spec == 'X')
		count += print_hex(va_arg(ap, unsigned int), 'X');
	else if (spec == '%')
		count += putchar('%');
	else
		count += write(1, &spec, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
			count += check_format(*(++str), ap);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}

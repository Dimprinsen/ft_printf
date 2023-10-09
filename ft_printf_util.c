/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:01:31 by ttinnerh          #+#    #+#             */
/*   Updated: 2023/10/09 20:02:05 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar(int c)
{
	return (write (1, &c, 1));
}

int	putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		count = write(1, "(null)", 6);
	else
	{
		while (*str != '\0')
		{
			putchar((int) *str);
			count++;
			str++;
		}
	}
	return (count);
}

int	print_digit(long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n) + 1);
	}
	else if (n < 10)
	{
		return (putchar(symbols[n]));
	}
	else
	{
		count = print_digit(n / 10);
		return (count + print_digit(n % 10));
	}
}

int	print_hex(long n, char spec)
{
	int		count;
	char	*symbols;

	if (spec == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 16)
	{
		return (putchar(symbols[n]));
	}
	else
	{
		count = print_hex(n / 16, spec);
		return (count + print_hex(n % 16, spec));
	}
}

int	print_pointer(unsigned long n)
{
	int		count;
	int		i;
	char	*symbols;
	char	output[16];

	i = 0;
	count = 0;
	symbols = "0123456789abcdef";
	if (n == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	while (n)
	{
		output[i++] = symbols[n % 16];
		n /= 16;
	}
	while (i--)
		count += putchar(output[i]);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:26:14 by ttinnerh          #+#    #+#             */
/*   Updated: 2023/10/09 19:59:22 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

int	putchar(int c);
int	putstr(char *str);
int	print_digit(long n);
int	print_hex(long n, char spec);
int	print_pointer(unsigned long n);
int	ft_printf(const char *str, ...);

#endif

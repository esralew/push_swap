/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elewin <elewin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:37:39 by elewin            #+#    #+#             */
/*   Updated: 2026/03/31 13:17:32 by elewin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_format(const char *format, va_list args);
static int	print_conversion(char specifier, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes_printed;

	if (!format)
		return (-1);
	va_start(args, format);
	bytes_printed = print_format(format, args);
	va_end(args);
	return (bytes_printed);
}

static int	print_format(const char *format, va_list args)
{
	int	i;
	int	bytes_printed;

	bytes_printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			bytes_printed += print_conversion(format[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			bytes_printed++;
			i++;
		}
	}
	return (bytes_printed);
}

static int	print_conversion(char specifier, va_list args)
{
	if (specifier == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (specifier == 'c')
		return (print_char(args));
	else if (specifier == 'p')
		return (print_pointer(args, specifier));
	else if (specifier == 's')
		return (print_str(args));
	else if (specifier == 'd' || specifier == 'i')
		return (print_int(args));
	else if (specifier == 'u')
		return (print_uint(args));
	else
		return (print_hex(args, specifier));
}

/*
#include <stdio.h>

int	main(void)
{
	int				num1;
	int				num2;
	char			*string;
	char			character;
	unsigned int	lowercase_hex;
	unsigned int	uppercase_hex;
	unsigned int	unsigned_int;
	int				*pointer;
	int				bytes_printed_myFunction;
	int				bytes_printed_defaultFunction;

	num1 = 987;
	num2 = -87438;
	string = NULL;
	character = 'b';
	lowercase_hex = -59;
	uppercase_hex = 89;
	pointer = NULL;
	unsigned_int = -5678966;
	//bytes_printed_defaultFunction = printf("");
	//printf("bytes printed default function: %d\n",
		bytes_printed_defaultFunction);
	//bytes_printed_myFunction = ft_printf("");
	//printf("bytes printed my function: %d\n", bytes_printed_myFunction);
	printf("Original Function:\n");
	bytes_printed_defaultFunction = printf("int: %i \nint 2: %d \n string:
			%s \nchar: %c \n %% \nlowercase_hex: %x \nuppercase_hex:
			%X \nunsigned int: %u \npointer: %p \n", num1, num2, string,
			character, lowercase_hex, uppercase_hex, unsigned_int, pointer);
	printf("bytes printed default function: %d\n",
		bytes_printed_defaultFunction);
	printf("\n\n");
	printf("My Function:\n");
	bytes_printed_myFunction = ft_printf("int: %i \nint 2: %d \n string:
			%s \nchar: %c \n %% \nlowercase_hex: %x \nuppercase_hex:
			%X \nunsigned int: %u \npointer: %p \n", num1, num2, string,
			character, lowercase_hex, uppercase_hex, unsigned_int, pointer);
	printf("bytes printed my function: %d\n", bytes_printed_myFunction);
	return (0);
}
*/
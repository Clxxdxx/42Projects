/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:27:56 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/13 11:35:20 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_number_decimal(int n, size_t *count)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		n = -n;
	}
	if (n > 9)
		print_number_decimal(n / 10, count);
	c = (n % 10) + '0';
	print_char(c, count);
}

void	print_number_unsigned(unsigned int n, size_t *count)
{
	char	c;

	if (n > 9)
		print_number_unsigned(n / 10, count);
	c = (n % 10) + '0';
	print_char(c, count);
}

void	print_num_hex_minus(int n, size_t *count)
{
	unsigned long	num;
	char			*hex_digits;
	char			str[16];
	int				i;

	i = 0;
	hex_digits = "0123456789abcdef";
	num = (unsigned int)n;
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	while (num > 0)
	{
		str[i] = hex_digits[num % 16];
		num /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		print_char(str[i], count);
	}
}

void	print_num_hex_mayus(int n, size_t *count)
{
	unsigned long	num;
	char			*hex_digits;
	char			str[16];
	int				i;

	i = 0;
	hex_digits = "0123456789ABCDEF";
	num = (unsigned int)n;
	if (num == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	while (num > 0)
	{
		str[i] = hex_digits[num % 16];
		num /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		print_char(str[i], count);
	}
}

/* int main()
{
    size_t count = 0;

    print_number_decimal(-1, &count);
    write(1, "\n", 1);

    print_number_decimal(0, &count);
    write(1, "\n", 1);

    print_number_decimal(-123, &count);
    write(1, "\n", 1);

    print_number_decimal(-2147483648, &count);
    write(1, "\n", 1);

    print_number_decimal(2147483647, &count);
    write(1, "\n", 1);

    write(1, "Total caracteres impresos: ", 26);
    print_number_decimal(count, &count);
    write(1, "\n", 1);

    return (0);
} */
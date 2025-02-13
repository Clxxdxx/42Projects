/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:02:57 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/13 13:09:46 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	formatter(va_list va, char *str, size_t *count)
{
	if (*str == 'c')
		print_char(va_arg(va, int), count);
	else if (*str == 's')
		print_string(va_arg(va, char *), count);
	else if (*str == 'p')
		print_pointer_void(va_arg(va, void *), count);
	else if (*str == 'd' || *str == 'i')
		print_number_decimal(va_arg(va, int), count);
	else if (*str == 'u')
		print_number_unsigned(va_arg(va, int), count);
	else if (*str == 'x')
		print_num_hex_minus(va_arg(va, int), count);
	else if (*str == 'X')
		print_num_hex_mayus(va_arg(va, int), count);
	else if (*str == '%')
		print_char('%', count);
}

int	ft_printf(char const *s, ...)
{
	va_list	va;
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	va_start(va, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			formatter(va, (char *)s, &count);
		}
		else
			print_char(*s, &count);
		s++;
	}
	va_end(va);
	return (count);
}

/* int main()
{
    ft_printf(" %i ", -1);
    return 0;
} */
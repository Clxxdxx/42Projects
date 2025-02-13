/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:33:31 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/13 11:44:06 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer_void(void *pointer, size_t *count)
{
	static const char	*hex_digits;
	unsigned long		num;
	char				str[16];
	int					i;

	hex_digits = "0123456789abcdef";
	i = 0;
	if (pointer == NULL)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	num = (unsigned long)pointer;
	print_char('0', count);
	print_char('x', count);
	while (num)
	{
		str[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (i--)
		print_char(str[i], count);
}

/*int main()
{
	int num = 42;
	char str[] = "Hola";
	int *ptr_num = &num;
	char *ptr_str = str;
	void *ptr_null = NULL;

	print_pointer_void(&num);
	write(1, "\n", 1);

	print_pointer_void(ptr_str);
	write(1, "\n", 1);

	print_pointer_void(ptr_null);
	write(1, "\n", 1);

	print_pointer_void(ptr_num);
	write(1, "\n", 1);

	print_pointer_void(&str);
	write(1, "\n", 1);

	return (0);
}*/

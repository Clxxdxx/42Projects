/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:34:14 by clalopez          #+#    #+#             */
/*   Updated: 2025/03/04 15:24:43 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	show_error(int argc, char **argv)
{
	if (error_non_integer(argc, argv) == 0)
		return (0);
	if (error_out_of_range(argc, argv) == 0)
		return (0);
	if (error_duplicate_number(argc, argv) == 0)
		return (0);
	return (1);
}
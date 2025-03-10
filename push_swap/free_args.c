/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clalopez <clalopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:11:13 by clalopez          #+#    #+#             */
/*   Updated: 2025/02/28 11:54:42 by clalopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_args(char **args)
{
    int i;
    if (!args)
        return;
    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

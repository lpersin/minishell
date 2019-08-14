/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:45:16 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/14 13:41:05 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int echo(char **args)
{
    while (*args)
    {
        ft_putstr(*args);
        args++;
        if (*args)
            ft_putchar(' ');
    }
    ft_putchar('\n');
    return (EXIT_SUCCESS);
}
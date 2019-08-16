/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:45:16 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/16 11:05:50 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int echo(t_cmd *cmd)
{
    char **args;

    args = cmd->args;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:45:16 by lpersin           #+#    #+#             */
/*   Updated: 2019/09/14 12:15:12 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_echo(t_cmd *cmd)
{
    char **args;
    int i;

    args = cmd->args;
    i = 0;
    while (*args)
    {
        ft_putstr(*args);
        if (i < cmd->var_num)
            ft_putchar(' ');
        args++;
    }
    ft_putchar('\n');
    return (EXIT_SUCCESS);
}
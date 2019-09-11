/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:08:17 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/24 15:29:33 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void        free_t_cmd(t_cmd *cmd)
{
    int     i;
    char    **args;

    if (cmd)
    {
        i = 0;
        args = cmd->args;
        while (i++ < cmd->var_num)
        {
            ft_memdel((void**)args);
            args++;
        }
        ft_memdel((void**)&cmd->args);
        ft_memdel((void**)&cmd->cmd);
        ft_memdel((void**)&cmd);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:08:17 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/20 17:30:23 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_t_cmd(t_cmd *cmd)
{
    char **args;

    if(cmd)
    {
        args = cmd->args;
        while (*args)
        {
            free(*args);
            *args = NULL;
            args++;
        }
        free(cmd->args);
        free(cmd->cmd);
        free(cmd);
    }
}
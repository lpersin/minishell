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
    if (cmd)
    {
        ft_str_array_free(cmd->args);
        ft_memdel((void**)&cmd->cmd);
        ft_memdel((void**)&cmd);
    }
}
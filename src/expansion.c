/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:55:01 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/28 19:04:14 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void swap_argument(char *args)
{

}

int expand_variables(t_cmd *cmd)
{
    char    **args;
    char    *tmp;

    args = cmd->args;
    while (*args)
    {
        if (*args[0] == '$' && *args[1] != '\0')
        {
            tmp = *args;
            *args = 
        }
    }
}


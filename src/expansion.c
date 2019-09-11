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


// static int expand_tilde(char *arg, char **env_p)
// {

// }

// static void expand_dollar(char *arg, char **env_p)
// {
    
// }

int expand_variables(t_cmd *cmd)
{
    char    **args;
    char    *tmp;

    if (cmd != NULL)
    {
        args = cmd->args;
        while (*args)
        {
            tmp = *args;
            if ((*args)[0] == '$' && (*args)[1] != '\0')
            {
                *args = get_env_var_val(*args + 1, *(cmd->env_p));
                free(tmp);
            }
            else if ((*args)[0] == '~' && (*args)[1] == '\0')
            {
                *args = get_env_var_val("HOME", *(cmd->env_p));
                if (*args == NULL)
                {
                    ft_putstr("No $home variable set.\n");
                    return (EXIT_FAILURE);
                }
                free(tmp);
            }
            else if ((*args)[0] == '~' && (*args)[1] == '/')
            {
                *args = ft_strjoin(get_env_var_val("HOME", *(cmd->env_p)), *args + 1);
                free(tmp);
            }
            args++;
        }
    }
    return (EXIT_SUCCESS);
}


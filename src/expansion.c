/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 18:55:01 by lpersin           #+#    #+#             */
/*   Updated: 2019/09/11 19:42:57 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_dollar(char **args, char **env_p)
{
    char *tmp;

	tmp = *args;
	*args = get_env_var_val(*args + 1, env_p);
    ft_memdel((void**)&tmp);
}

static int	expand_tilde(char **args, char **env_p)
{
	char *tmp;
	char *val;

	tmp = *args;
	val = get_env_var_val("HOME", env_p);
	if (val == NULL)
	{
		ft_putstr("No $HOME variable set.\n");
		return (EXIT_FAILURE);
	}
	if ((*args)[1] == '\0')
	{
		*args = val;
		ft_memdel((void**)&tmp);
	}
	if ((*args)[1] == '/')
	{
		*args = ft_strjoin(val, *args + 1);
		ft_memdel((void**)&val);
        ft_memdel((void**)&tmp);
	}
	return (EXIT_SUCCESS);
}

int 		expand_variables(t_cmd *cmd)
{
    char    **args;

    if (cmd != NULL)
    {
        args = cmd->args;
        while (*args)
        {
            if ((*args)[0] == '$' && (*args)[1] != '\0')
				expand_dollar(args, *(cmd->env_p));
			if ((*args)[0] == '~')
				if (expand_tilde(args, *(cmd->env_p)) == EXIT_FAILURE)
					return (EXIT_FAILURE); 
            args++;
        }
    }
    return (EXIT_SUCCESS);
}


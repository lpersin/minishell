/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:35:00 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/28 17:36:34 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void del_var_env(char *var, char ***env_p)
{
	char	**target;
	target = get_env_var_ptr(var, *env_p);
	if (target != NULL)
		*env_p = ft_str_array_del(*env_p, *target);
}

int		ft_unsetenv(t_cmd *cmd)
{
	char	**args;
	int		i;

	args = cmd->args;
	i = 0;
	if (cmd->var_num == 0)
	{
		ft_putstr("unsetenv: Too few arguments.\n");
		return (EXIT_FAILURE);
	}
	else
	{
		while (i++ < cmd->var_num)
		{
			if(*args)
				del_var_env(*args, cmd->env_p);
			args++;
		}
		return (EXIT_SUCCESS);
	}
}
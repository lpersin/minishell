/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:35:30 by lpersin           #+#    #+#             */
/*   Updated: 2019/09/11 19:43:19 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*build_env_entry(char	*var, char *value)
{
	char	*entry;

	entry = ft_strnew(ft_strlen(var) + ft_strlen(value) + 1);
	ft_strcat(entry, var);
	ft_strcat(entry, "=");
	ft_strcat(entry, value);
	return (entry);
}

void		add_var_env(char *var, char *value, char ***env_p)
{
	char	**target;
	char	*new_entry;

	new_entry = build_env_entry(var, value);
	target = get_env_var_ptr(var, *env_p);
	if (target)
	{
		ft_memdel((void**)target);
		*target = new_entry;
	}
	else
		*env_p = ft_str_array_add(*env_p, new_entry);
}

int			ft_setenv(t_cmd *cmd)
{	
	if (cmd->args[0] == NULL)
		print_env(*(cmd->env_p));
	else if (!ft_strisalnum(cmd->args[0]))
	{
		ft_putstr("setenv: Variable name must contain alphanumeric characters.\n");
		return (EXIT_FAILURE);
	}
	else if (!ft_isalpha(cmd->args[0][0]))
	{
		ft_putstr("setenv: Variable name must begin with a letter.\n");
		return (EXIT_FAILURE);
	}
	else if (cmd->args[1] == NULL)
		add_var_env(cmd->args[0], "", cmd->env_p);
	else if (cmd->args[2] == NULL)
		add_var_env(cmd->args[0], cmd->args[1], cmd->env_p);
	else
	{
		ft_putstr("setenv: too many arguments\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:53:05 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/24 19:47:11 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_environ()
{
	extern char	**environ;
	char		**env_p;

	env_p = ft_str_array_deepcopy(environ);
	return (env_p);
}

static void	print_env(char **env_p)
{
	while (*env_p)
	{
		ft_putstr(*env_p);
		ft_putchar('\n');
		env_p++;
	}
}

char	**get_env_var_ptr(char *var, char **env_p)
{
	size_t	var_len;

	var_len = ft_strlen(var);
	while (*env_p)
	{
		if (!ft_strncmp(var, *env_p, var_len) && (*env_p)[var_len] == '=')
			return (env_p);
	env_p++;
	}
	return (NULL);
}

static char	*get_env_entry(char	*var, char *value)
{
	char	*entry;

	entry = ft_strnew(ft_strlen(var) + ft_strlen(value) + 1);
	ft_strcat(entry, var);
	ft_strcat(entry, "=");
	ft_strcat(entry, value);
	return (entry);
}

static void	add_var_env(char *var, char *value, char ***env_p)
{
	char	**target;
	char	*new_entry;

	new_entry = get_env_entry(var, value);
	target = get_env_var_ptr(var, *env_p);
	if (target != NULL)
	{
		ft_memdel((void**)target);
		*target = new_entry;
	}
	else
		*env_p = ft_str_array_add(*env_p, new_entry);
}

int		ft_setenv(t_cmd *cmd)
{
	if (cmd->args[0] == NULL)
		print_env(*(cmd->env_p));
	else if (cmd->args[1] == NULL)
		add_var_env(cmd->args[0], "", cmd->env_p);
	else if (cmd->args[2] == NULL)
		add_var_env(cmd->args[0], cmd->args[1], cmd->env_p);
	else
	{
		ft_putstr("minishell: setenv: too many arguments");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
NOTE FOR ENV !!!
SUBSTITUTION IS DONE BEFORE EXECUTING COMMANDS
AND COMMANDS ARE EXECUTED IN A FORKED PROCESS
AND ONLY EXTERNAL COMMANDS CAN BE EXECUTED NOT BUILTINS
THATS WHY env -i /bin/echo $HOME WORKS and env -i /usr/bin/cd $HOME
DOESN't MOVE YOU
*/
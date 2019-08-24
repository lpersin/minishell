/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:53:05 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/21 22:03:32 by lpersin          ###   ########.fr       */
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

void	print_env(char **env_p)
{
	while (*env_p)
	{
		ft_putstr(*env_p);
		ft_putchar('\n');
		env_p++;
	}
}

char	*env_lookup(char *var, char **env_p)
{
	char *offset;

	while(*env_p)
	{
		if ((offset = ft_strrchr(*env_p, '=')) != NULL)
			if (!ft_strncmp(var, *env_p, (offset - *env_p)))
				return (offset + 1);
	env_p++;
	}
	return (NULL);
}

static void	add_var_env(char *var, char *value, char ***env_p)
{

}

int		*setenv(t_cmd *cmd)
{
	if (cmd->args[0] == NULL)
		print_env(cmd->env_p);
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
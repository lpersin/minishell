/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:53:05 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/28 17:44:11 by lpersin          ###   ########.fr       */
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

char	**get_env_var_ptr(char *var, char **env_p)
{
	size_t	var_len;

	var_len = ft_strlen(var);
	while (*env_p)
	{
		if (!ft_strncmp(var, *env_p, var_len) && (*env_p)[var_len] == '=' 
						&& ((size_t) (ft_strchr(*env_p, '=') - *env_p)) == var_len)
			return (env_p);
	env_p++;
	}
	return (NULL);
}

/*
NOTE FOR ENV !!!
SUBSTITUTION IS DONE BEFORE EXECUTING COMMANDS
AND COMMANDS ARE EXECUTED IN A FORKED PROCESS
AND ONLY EXTERNAL COMMANDS CAN BE EXECUTED NOT BUILTINS
THATS WHY env -i /bin/echo $HOME WORKS and env -i /usr/bin/cd $HOME
DOESN't MOVE YOU
*/
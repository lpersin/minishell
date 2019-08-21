/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:53:05 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/21 12:33:08 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_environ()
{
	extern char	**environ;
	char		**env_p;

	env_p = ft_deepcopy_str_array(environ);
	return (env_p);
}


void print_env(char **env_p)
{
	while (*env_p)
	{
		ft_putstr(*env_p);
		env_p++;
	}
}
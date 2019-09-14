/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:06:19 by lpersin           #+#    #+#             */
/*   Updated: 2019/09/14 11:06:08 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



static int	change_w_directory(char *path)
{
	if (path)
		;
	return (EXIT_SUCCESS);
}

int	ft_cd(t_cmd *cmd)
{
	char *path;
	
	if (cmd->var_num > 1)
		return(ft_exit_f("minishell: cd: too many arguments"));
	if (cmd->var_num == 0)
	{
		path = get_env_var_val("HOME", *(cmd->env_p));
		if (path == NULL)
			return(ft_exit_f("minishell: cd: HOME not set"));
		else
			change_w_directory(path);
	}
	if (!ft_strcmp(*(cmd->args), "-"))
	{
		path = get_env_var_val("OLDPWD", *(cmd->env_p));
		if (path == NULL)
			return(ft_exit_f("minishell: cd: OLDPWD not set"));
		else
		{
			ft_putstr(path);
			change_w_directory(path);
		}
	}
	else
		change_w_directory(*(cmd->args));
	
	return (EXIT_SUCCESS);
}
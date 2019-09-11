/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:06:19 by lpersin           #+#    #+#             */
/*   Updated: 2019/09/11 19:40:52 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cd(t_cmd *cmd)
{
	if (cmd->var_num > 1)
	{
		ft_putstr("cd: too many arguments");
		return (EXIT_FAILURE);
	}
	
	return (EXIT_SUCCESS);
}
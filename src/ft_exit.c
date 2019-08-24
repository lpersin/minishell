/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:51:16 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/24 15:24:22 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exit(t_cmd *cmd)
{
	ft_str_array_free(*(cmd->env_p));
	free_t_cmd(cmd);
	ft_putstr("exit\n");
	exit(EXIT_SUCCESS);	
}
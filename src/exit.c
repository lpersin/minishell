/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:51:16 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/16 11:13:48 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exit(t_cmd *cmd)
{
	free_t_cmd(cmd);
	ft_putstr("exit\n");
	exit(EXIT_SUCCESS);	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:43:11 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/14 11:55:16 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
# include <limits.h>
# include "libft.h"

typedef struct  s_cmd
{
    char        *cmd;
    char        **args;
    int         var_num;
}               t_cmd;

void    exec_builtin_cmd();
void    exec_cmd();
void    parse_command(char *cmd_line, t_cmd **cmd);
int     echo(char **args);

#endif
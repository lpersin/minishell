/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:43:11 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/21 10:53:03 by lpersin          ###   ########.fr       */
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
    char        **env_p;
    int         var_num;
}               t_cmd;

typedef struct  s_fct_table_entry
{
    char        *fct_name;
    int        (*fct)(t_cmd*);
}               t_fct_table_entry;

void    exec_builtin_cmd();
void    exec_cmd();
void    parse_command(char *cmd_line, t_cmd **cmd);
void    free_t_cmd(t_cmd *cmd);
int     ft_echo(t_cmd *cmd);
int     ft_exit(t_cmd *cmd);
int     ft_cd(t_cmd *cmd);
char	**copy_environ();

#endif
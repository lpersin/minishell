/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:42:54 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/27 19:16:13 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static int      is_builtin_cmd(t_cmd *cmd)
{  
    int     array_size;
    char    *builtins[] = {"echo", "cd", "setenv", "unsetenv", "env", "exit"};

    if (cmd != NULL && cmd->cmd != NULL)
    {
        array_size = sizeof(builtins) / sizeof(builtins[0]);
        while (array_size--)
            if (!ft_strcmp(cmd->cmd, builtins[array_size]))
                return 1;
    }
    return 0;
}

static void     print_prompt()
{
    ft_putstr("$> ");
}

static t_cmd    *get_t_cmd()
{
    char    *cmd_line;
    t_cmd   *cmd;

    cmd_line = NULL;
    cmd = NULL;
    get_next_line(STDIN_FILENO, &cmd_line);
    parse_command(cmd_line, &cmd);
    ft_memdel((void**)&cmd_line);
    return cmd;
}

int main()
{
    t_cmd   *cmd;
    char    **env_p;

    env_p = copy_environ();
    while (1)
    {
        print_prompt();
        cmd = get_t_cmd();
        cmd->env_p = &env_p;
        if (is_builtin_cmd(cmd))
            exec_builtin_cmd(cmd);
        else
            exec_external_cmd(cmd);
        free_t_cmd(cmd);
    }
    return (EXIT_SUCCESS);
}
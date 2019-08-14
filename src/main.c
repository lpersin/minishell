/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:42:54 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/14 10:41:56 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

static int is_builtin_cmd(t_cmd *cmd)
{
    int     i;
    char    *builtins[] = {"echo", "cd", "setenv", "unsetenv", "env", "exit"};

    i = 0;
    while (i < 6)
    {
        if (ft_strcmp(cmd->cmd, builtins[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

static void print_prompt()
{
    ft_putstr("$> ");
}
    
int main()
{
    //extern char **environ;
    while(1)
    {
        pid_t   child_pid;
        char    *cmd_line;
        t_cmd   *cmd;
        int     status;
        
        print_prompt();
        get_next_line(STDIN_FILENO, &cmd_line);
        parse_command(cmd_line, &cmd);
        if (is_builtin_cmd(cmd))
            exec_builtin_cmd(cmd);
        else
        {
            child_pid = fork();
            if (child_pid == 0)
                exec_cmd(cmd); //calls execvp
            else
                waitpid(child_pid, &status, 0);
        }
    }
    return (EXIT_SUCCESS);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:36:32 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/14 11:54:59 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void init_t_cmd(t_cmd **cmd)
{
    if (((*cmd = (t_cmd*)malloc(sizeof(t_cmd))) == NULL))
        exit(EXIT_FAILURE);  //should free memory then exit here
    (*cmd)->cmd = NULL;
    (*cmd)->args = NULL;
    (*cmd)->var_num = 0;
}

static void load_t_cmd(char **words, t_cmd **cmd)
{   
    init_t_cmd(cmd);
    if(words[0] != NULL)
    {
        (*cmd)->cmd = words[0];
        words++;
        (*cmd)->args = words;
        while (*words != NULL)
        {
            (*cmd)->var_num++;
            words++;
        }
    }
}

void parse_command(char *cmd_line, t_cmd **cmd)
{   
    char    **words;

     if (cmd_line != NULL && *cmd_line != '\0')
        if ((words = ft_strsplit(cmd_line, ' ')) != NULL)
            load_t_cmd(words, cmd);
        
}
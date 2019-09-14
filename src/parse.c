/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:36:32 by lpersin           #+#    #+#             */
/*   Updated: 2019/09/14 13:18:50 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char **sanitize_args(char **words, char **env_p)
{
	int i = 0;

	while (words[i])
    {
		if (words[i][0] == '$' && words[i][1] != '\0')
		{
			if (get_env_var_ptr(words[i] + 1, env_p) == NULL)
			{
				words = ft_str_array_del(words, words[i]);
				i = -1;
			}
		}
		i++;
    }
    return (words);
}

static void init_t_cmd(t_cmd **cmd)
{
    if (((*cmd = (t_cmd*)malloc(sizeof(t_cmd))) == NULL))
        exit(EXIT_FAILURE);  //should free memory then exit here
    (*cmd)->cmd = NULL;
    (*cmd)->args = NULL;
    (*cmd)->env_p = NULL;
    (*cmd)->var_num = 0;
}

static void load_t_cmd(char **words, t_cmd **cmd)
{
    init_t_cmd(cmd);
    if (words[0] != NULL)
    {
        (*cmd)->cmd = words[0];
        (*cmd)->var_num = ft_str_array_size(&(words[1]));
        (*cmd)->args = ft_str_array_copy(&(words[1]));
    }
}

void parse_command(char *cmd_line, t_cmd **cmd, char **env_p)
{   
    char    **words;

     if (cmd_line != NULL && *cmd_line != '\0')
        if ((words = ft_strsplit(cmd_line, ' ')) != NULL)
        {
            words = sanitize_args(words, env_p);
            load_t_cmd(words, cmd);
            ft_memdel((void**)&words);
        }
}
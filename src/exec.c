/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 20:18:37 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/16 11:17:50 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*fct_lookup(const char *fct_name)
{
	int i;
	int num_tables_entries;
	t_fct_table_entry	fct_table[] = {{"echo", echo}, {"exit", ft_exit}};

	i = 0;
	num_tables_entries = sizeof(fct_table) / sizeof(t_fct_table_entry);
	if (!fct_name)
		return NULL;
	while (i < num_tables_entries)
	{
		if (!ft_strcmp(fct_name, fct_table[i].fct_name))
			return fct_table[i].fct;
		i++;
	}
	return NULL;
}

void 		exec_builtin_cmd(t_cmd *cmd)
{
	int (*builtin) (t_cmd*);
	builtin = fct_lookup(cmd->cmd);
	builtin(cmd);
}

void 		exec_cmd()
{
	
}
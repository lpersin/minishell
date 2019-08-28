/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_contains.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:30:37 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/28 16:18:10 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_array_contains(char **arr, char *str)
{
	while (arr)
	{
		if (!ft_strcmp(*arr, str))
			return (1);
		arr++;
	}
	return (0);
}
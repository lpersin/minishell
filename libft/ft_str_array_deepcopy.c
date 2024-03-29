/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_deepcopy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:29:06 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/24 14:46:36 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str_array_deepcopy(char **arr)
{
	char	**dst;
	int		i;

	i = 0;
	dst = ft_str_array_copy(arr);
	while (arr[i])
	{
		dst[i] = ft_strdup(arr[i]);
		i++;
	}
	return dst;
}
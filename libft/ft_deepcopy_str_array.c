/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deepcopy_str_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 12:29:06 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/21 15:57:07 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_deepcopy_str_array(char **arr)
{
	char	**dst;
	int		i;

	i = 0;
	dst = ft_copy_str_array(arr);
	while (dst[i])
	{
		ft_strcpy(dst[i], arr[i]);
		i++;
	}
	return dst;
}
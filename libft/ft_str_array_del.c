/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 18:09:02 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/28 16:39:06 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_array(char **src, char **dst, char *target)
{
	int found;
	int	i;
	int	j;

	i = 0;
	j = 0;
	found = 0;
	while (src[j])
	{
		if (!found && !ft_strcmp(src[j], target))
		{
			ft_memdel((void**)&src[i]);
			j++;
			found = 1;
		}
		dst[i++] = src[j];
		if (src[j])
			j++;
	}
}

char		**ft_str_array_del(char **arr, char *target)
{
	char	**new_arr;
	int		arr_size;

	arr_size = ft_str_array_size(arr);
	if (arr_size == 0 || !ft_str_array_contains(arr, target))
		return (arr); 
	if (((new_arr = (char**)malloc(sizeof(char*) * arr_size)) != NULL))
	{
		copy_array(arr, new_arr, target);
		new_arr[arr_size - 1] = NULL;
		ft_memdel((void**)&arr);
	}
	return (new_arr);
}
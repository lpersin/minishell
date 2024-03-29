/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 10:36:03 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/21 19:41:45 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies char* pointers to new array of pointers
** WARNING: DOESN'T COPY CHAR ARRAYS 
*/

char	**ft_str_array_copy(char **src)
{
	char	**dst;
	int		arr_size;

	arr_size = ft_str_array_size(src);
	if ((dst = (char**)malloc(sizeof(char*) * (arr_size + 1))) != NULL)
		ft_memcpy(dst, src, sizeof(char*) * (arr_size + 1));
	return (dst);
}
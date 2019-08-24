/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:08:01 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/24 18:19:51 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
    ** Doesn't allocate memory for string to be added
    ** Just adds new entry pointing to new string in **arr
*/

char    **ft_str_array_add(char **arr, char *str)
{
    char    **new_arr;
    int     arr_size;

    arr_size = ft_str_array_size(arr);
    if (((new_arr = (char**)malloc(sizeof(char*) * (arr_size + 2))) != NULL))
    {
        ft_memcpy(new_arr, arr, sizeof(char*) * (arr_size + 1));
        new_arr[arr_size] = str;
        new_arr[arr_size + 1] = NULL;
        ft_memdel((void**)&arr);
    }
    return new_arr;
}
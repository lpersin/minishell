/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_array_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 14:54:53 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/24 15:08:32 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_str_array_free(char **arr)
{
    char    **tmp;

    tmp = arr;
    while (*tmp)
    {
        ft_memdel((void**)tmp);
        tmp++;
    }
    ft_memdel((void**)&arr);
}
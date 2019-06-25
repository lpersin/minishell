/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:09:40 by lpersin           #+#    #+#             */
/*   Updated: 2019/04/24 15:23:19 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(char *str, char c, size_t nb)
{
	if (str != NULL)
	{
		while (nb--)
		{
			*str = c;
			str++;
		}
	}
	return (str);
}
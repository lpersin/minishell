/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:43:34 by lpersin           #+#    #+#             */
/*   Updated: 2018/07/04 16:52:28 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_maxi(int *tab, size_t size)
{
	int		max;
	size_t	i;

	max = tab[0];
	i = 0;
	while (i < size)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpersin <lpersin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:53:19 by lpersin           #+#    #+#             */
/*   Updated: 2019/08/21 16:20:32 by lpersin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*strsub;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	strsub = ft_strnew(len);
	if (strsub)
	{
		while (i < len)
		{
			strsub[i] = s[start + i];
			i++;
		}
	}
	return (strsub);
}

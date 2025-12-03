/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:53:54 by zeyildir          #+#    #+#             */
/*   Updated: 2025/07/03 13:06:56 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	to_find;
	int				i;

	to_find = (unsigned char)c;
	i = ft_strlen(s);
	if (to_find == '\0')
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == to_find)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}

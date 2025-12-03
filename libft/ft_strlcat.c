/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:53:42 by zeyildir          #+#    #+#             */
/*   Updated: 2025/07/03 13:06:29 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sdst;
	size_t	ssrc;
	size_t	i;

	sdst = ft_strlen(dst);
	ssrc = ft_strlen(src);
	i = 0;
	if (size <= sdst)
	{
		return (size + ssrc);
	}
	while (src[i] != '\0' && sdst + i + 1 < size)
	{
		dst[i + sdst] = src[i];
		i++;
	}
	dst[sdst + i] = '\0';
	return (sdst + ssrc);
}

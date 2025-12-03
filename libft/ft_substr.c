/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:54:00 by zeyildir          #+#    #+#             */
/*   Updated: 2025/07/03 13:07:04 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	size_t	leng;
	size_t	slen;

	slen = 0;
	i = 0;
	leng = ft_strlen(s);
	if (leng <= start)
		return (ft_strdup(""));
	if (len > leng - start)
		slen = leng - start;
	else
		slen = len;
	ptr = malloc((slen + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < slen && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

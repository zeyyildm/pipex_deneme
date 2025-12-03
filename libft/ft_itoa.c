/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeyildir <zeyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:53:04 by zeyildir          #+#    #+#             */
/*   Updated: 2025/07/03 13:53:04 by zeyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennumber(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*numbertochar(int lennnumber, int n, char *str)
{
	int		sign;

	sign = 0;
	str[lennnumber--] = '\0';
	if (n == -2147483648)
	{
		str[lennnumber--] = 8 + '0';
		n = -214748364;
	}
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (lennnumber >= 0)
	{
		str[lennnumber--] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		lennnumber;

	lennnumber = lennumber(n);
	str = malloc(sizeof(char) * lennnumber + 1);
	if (!str)
		return (NULL);
	str = numbertochar(lennnumber, n, str);
	return (str);
}

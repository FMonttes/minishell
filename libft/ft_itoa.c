/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:19:00 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 10:45:08 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_transform(long int nb, char *str, int i)
{
	while (nb > 0)
	{
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	i = ft_count(n);
	nb = n;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		free(str);
		str[0] = '-';
		nb *= -1;
	}
	str[i--] = '\0';
	ft_transform(nb, str, i);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:02:27 by fmontes           #+#    #+#             */
/*   Updated: 2023/10/18 14:24:31 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	i;
	int	result;
	int	count;

	count = 1;
	sign = 0;
	i = 0;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			count = count * -1;
		sign++;
		if (sign > 1)
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = (result * 10) + nptr[i++] - '0';
	return (result * count);
}

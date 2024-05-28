/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:57:17 by fmontes           #+#    #+#             */
/*   Updated: 2023/10/30 10:56:26 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long nbr)
{
	int		size;
	long	num;

	size = 0;
	if (nbr == 0)
		size = 1;
	else
	{
		if (nbr < 0)
		{
			size++;
			nbr *= -1;
		}
		num = nbr;
		while (num > 0)
		{
			size++;
			num /= 10;
		}
	}
	return (size);
}

static void	conditions(long n, char *newstr, long j, int strsize)
{
	if (n == 0)
		newstr[0] = '0';
	else
	{
		j = strsize - 1;
		if (n < 0)
		{
			newstr[0] = '-';
			n *= -1;
		}
		while (n != 0)
		{
			newstr[j] = n % 10 + '0';
			n /= 10;
			j--;
		}
	}
}

char	*ft_itoa(int n)
{
	long	a;
	int		j;
	int		strsize;
	char	*newstr;

	a = n;
	j = 0;
	strsize = count(a);
	newstr = (char *)malloc(strsize + 1);
	if (newstr == NULL)
		return (NULL);
	conditions(a, newstr, j, strsize);
	newstr[strsize] = '\0';
	return (newstr);
}

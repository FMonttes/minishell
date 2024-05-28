/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:40:14 by fmontes           #+#    #+#             */
/*   Updated: 2023/10/30 11:10:58 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	if ((!big || !little) && len == 0)
		return (NULL);
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && count < len)
	{
		while (big[i + j] == little[j] && count <= len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
			count++;
		}
		j = 0;
		count++;
		i++;
	}
	return (NULL);
}

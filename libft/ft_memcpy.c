/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:28:14 by fmontes           #+#    #+#             */
/*   Updated: 2023/10/30 10:29:39 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destt;
	unsigned char	*srcc;

	i = 0;
	destt = (unsigned char *)dest;
	srcc = (unsigned char *) src;
	if (destt == 0 && srcc == 0)
		return (NULL);
	while (i < n)
	{
		*destt = *srcc;
		destt++;
		srcc++;
		i++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:34:04 by fmontes           #+#    #+#             */
/*   Updated: 2023/10/30 10:30:45 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destiny;
	unsigned char	*source;

	i = 0;
	destiny = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (destiny == 0 && source == 0)
		return (NULL);
	if (destiny < source || destiny >= (source + n))
	{
		while (i < n)
		{
			*destiny++ = *source++;
			i++;
		}
	}
	else
	{
		destiny += n - 1;
		source += n - 1;
		while (n--)
			*(destiny--) = *(source--);
	}
	return (dest);
}

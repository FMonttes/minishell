/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 09:58:01 by fmontes           #+#    #+#             */
/*   Updated: 2023/10/19 10:07:39 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(src);
	while (i < size && dst[i] != '\0')
		i++;
	k = i;
	while ((i + 1 < size) && src[i - k] != '\0')
	{
		dst[i] = src[i - k];
		i++;
	}
	if (k < size)
		dst[i] = '\0';
	return (j + k);
}

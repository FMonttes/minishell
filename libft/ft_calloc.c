/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:45:54 by fmontes           #+#    #+#             */
/*   Updated: 2023/10/30 10:44:10 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(nmemb * size);
	if (ptr != NULL)
	{
		ptr = ft_memset(ptr, 0, nmemb * size);
		return (ptr);
	}
	else
	{
		ptr = NULL;
		return (ptr);
	}
}

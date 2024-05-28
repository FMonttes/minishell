/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:47:04 by fmontes           #+#    #+#             */
/*   Updated: 2023/10/30 11:14:00 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!s)
		return (NULL);
	if (!str)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		if (start >= ft_strlen(s))
		{
			str[i] = '\0';
			return (str);
		}
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

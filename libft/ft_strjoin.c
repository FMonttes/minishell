/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:45:38 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 08:30:22 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	if (newstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
		newstr[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		newstr[j++] = s2[i++];
	newstr[j] = '\0';
	return (newstr);
}

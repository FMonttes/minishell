/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:34:15 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/23 12:22:39 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *first_word(char *input)
{
    int     j;
    int     i;
    int     x;
    char    *ret;

    i = 0;
    j = 0;
    x = 0;
    while (input[i] == ' ' || input[i] == '\t')
    {
		j++;
        i++;
    }
	while (input[i] != '\0' && input[i] != ' ' && input[i] != '\t')
		i++;
	ret = malloc(i - j + 1);
    while (input[j] && input[j] != ' ' && input[j] != '\t')
        ret[x++] = input[j++];
    ret[x] = '\0';
    return (ret);
}

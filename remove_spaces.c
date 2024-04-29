/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:47:20 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/29 09:06:51 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "minishell.h"

char *remove_spaces(char *input)
{
    int i;
    int j = 0;
    char *ret;

    i = 0;
    while (input[i] == ' ' || input[i] == '\t')
        i++;
    while (input[i])
    {
        while(input[i] == ' ' || input[i] == '\t') {
            i++;
            j++;
        }
        i++;
    }
    ret = malloc(i - j + 1);
    i = 0;
    j = 0;
    while (input[i])
    {
        while(input[i] == ' ' || input[i] == '\t')
            i++;
        ret[j++] = input[i++];
    }
    ret[j] = '\0';
    return ret;
}*/
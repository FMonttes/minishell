/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_extra_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:24:09 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/23 12:23:08 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *remove_e_spaces(char *input)
{
    int i = 0;
    int flg = 0;
    int x = 0;

    char *ret = malloc(10000);

    while (input[i] == ' ' || input[i] == '\t')
        i += 1;
    while (input[i])
    {
        if (input[i] == ' ' || input[i] == '\t')
            flg = 1;
        if (!(input[i] == ' ' || input[i] == '\t'))
        {
            if (flg)
                ret[x++] = ' ';
            flg = 0;
            ret[x++] = input[i];
        }
        i += 1;
    }
    ret[x] = '\0';

    return ret;
}

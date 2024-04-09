/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:35:30 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/09 17:42:47 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    unset(char *input, char **env)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    str = ft_strdup(input + 6);
    while (env[i])
    {
        if (strncmp(env[i], str, ft_strlen(str)) == 0)
        {
            free(env[i]);
            j = i;
        }
        while (env[j])
            env[j++] = env[j + 1];
        i++;
    }
    free(str);
}
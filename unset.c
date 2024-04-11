/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:35:30 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/11 15:17:20 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    unset(char *input, char **env)
{
    int     i;
    int     j;
    char    *str;
    char    *cmd;

    i = 0;
    cmd = strq(input, "unset");
    cmd = remove_extra_spaces(cmd);
    if (count_quotes(input) % 2 == 0)
    {
        while (env[i])
        {
            if (strncmp(env[i], cmd + 6, ft_strlen(cmd + 6)) == 0)
            {
                free(env[i]);
                j = i;
            }
            while (env[j])
                env[j++] = env[j + 1];
            i++;
        }
    }
}
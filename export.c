/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:26:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/07 14:48:04 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// preciso verificar os inputs com ' ou "

/*void creat_env(char *input, char **env)
{
    int i = 0;
    char *cmd;

    cmd = strq(input, "export");
    cmd = remove_extra_spaces(cmd, 0);
    if (count_quotes(input) % 2 == 0)
    {
        if (strncmp(cmd, "export", ft_strlen(cmd)) == 0)
        {
            if (env == NULL)
                exit(1);
            while (env[i] != NULL)
                i++;
            env[i] = malloc(ft_strlen(cmd + 7));
            env[i] = ft_strdup(cmd + 7);
            if (env[i] == NULL)
                exit(1);
        }
    }
    env[i + 1] = NULL;
}
*/

/*char **creat_env(char *input, char **env)
{
    int i = 0;
    char *cmd;

    cmd = strq(input, "export");
    cmd = remove_extra_spaces(cmd, 0);
    while (env[i])
        i++;
    char **new_env = malloc(sizeof(char *) * (i + 1));
    if (count_quotes(input) % 2 == 0)
    {
        if (strncmp(cmd, "export", ft_strlen(cmd)) == 0)
        {
            while (env[i])
                new_env[i] = malloc(ft_strlen(env[i++]) + 1);
            i = 0;
            while (env[i])
                new_env[i] = env[i++];
            new_env[i] = NULL;
        }
    }
    return new_env;
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:33:30 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/02 17:49:40 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *strq(char *input)
{
    int     i;
    int     x;
    char    *cmd;
    
    i = 0;
    x = 0;
    cmd = malloc(ft_strlen("env") + 1);
    while (input[i])
    {
        if (input[i] == 39 || input[i] == 34)
            i++;
        else
            cmd[x++] = input[i++];
    }
    cmd[x] = '\0'; 
    if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0)
        return (cmd);
    return ("syntax error");
}

void    print_env(char *input, char **env)
{
    int     i;
    int     x;
    char    *cmd;

    x = 0;
    cmd = strq(input);
    if (count_quotes(input) % 2 == 0)
    {
        if (strncmp(cmd, "env", ft_strlen(cmd)) == 0)
        {
            while (env[x])
            {
                i = 0;
                while (env[x][i])
                    i++;
                printf("%s\n", env[x]);
                x++;
            }
        }
    }
    else
        printf("invalid syntax\n");
}
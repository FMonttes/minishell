/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:26:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/09 16:36:10 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//preciso verificar os inputs com ' ou "

void  creat_env(char *input, char **env) 
{
    int i = 0;
    char    *cmd;

    if (env == NULL)
        exit(1);
    while (env[i] != NULL)
        i++;
    env[i] = ft_strdup(input + 7);
    if (env[i] == NULL)
        exit(1);
    env[i + 1] = NULL;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:10:02 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/03 16:29:50 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    ft_exit(char *input)
{
    char    *cmd;

    cmd = strq(input, "exit");
    if (ft_strncmp(cmd, "exit", ft_strlen("exit")) == 0
    && count_quotes(input) % 2 == 0)
    {
        printf("exit\n");
        return (0);
    }
    else
        printf("exit: command not found\n");
}
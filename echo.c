/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/11 14:46:43 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     count_quotes(char *input)
{
    int     i;
    int     quotes;

    i = 0;
    quotes = 0;
    while (input[i])
    {
        if (input[i] == 39 || input[i] == 34)
            quotes++;
        i++;
    }
    return quotes;
}

void   echo(char *input)
{
    int     i;
    char    *cmd;
    char    *cmd2;

    i = 0;
    cmd = strq(input, "echo");
    cmd = remove_extra_spaces(cmd);
    cmd2 = strq(input, "echo -n");
    cmd2 = remove_extra_spaces(cmd);
    if (count_quotes(input) % 2 == 0)
    {
        if (ft_strncmp(cmd2, "echo -n", ft_strlen("echo -n")) == 0)
            printf("%s", cmd2 + 8);
        else if (ft_strncmp(cmd, "echo", ft_strlen("echo")) == 0)
            printf("%s\n", cmd + 5);
    }
    else
        printf("invalid syntax\n");
}

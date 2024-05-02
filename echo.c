/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/02 16:16:36 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count_quotes(char *input)
{
    int i;
    int quotes;

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

void echo(char *input)
{
    int i;
    char *cmd;
    char *cmd2;

    i = 0;
    cmd = strq(input, "echo");
    cmd = remove_extra_spaces(cmd);
    cmd2 = strq(input, "echo -n");
    cmd2 = remove_extra_spaces(cmd2);
    char **arg = ft_split(input, ' ');
    if (count_quotes(input) % 2 == 0)
    {
        if (ft_strncmp("echo", arg[0], ft_strlen(arg[0])) == 0 &&
            hidenp("-n", arg[1]) == 1)
            printf("%s", arg[2]);
        else if (ft_strncmp(arg[0], "echo", ft_strlen(arg[0])) == 0)
            printf("%s\n", cmd + 5);
    }
    else
        printf("invalid syntax\n");
}

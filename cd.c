/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:07:19 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/07 10:43:55 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void cd(char *input)
{
    char *cmd;

    cmd = strq(input, "cd");
    cmd = remove_extra_spaces(cmd, 0);
    if (count_quotes(input) % 2 == 0)
    {
        if (chdir(cmd + 3) == 0)
            return;
        else if (chdir(getenv("HOME")) == 0)
            return;
        else
            printf("diretorio inexistente\n");
    }
}
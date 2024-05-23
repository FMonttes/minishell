/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:07:19 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/23 12:22:15 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void cd(char *input)
{
    char *cmd;

    cmd = ft_strnstr(input, "cd", ft_strlen(input));
    if (cmd != NULL)
    {
        if (ft_strncmp("cd", input, ft_strlen(input)) == 0)
        {
            chdir(getenv("HOME"));
            return;
        }
        cmd = remove_extra_spaces(cmd + 2, 0);
        if (count_quotes(input) % 2 == 0)
        {
            if (chdir(cmd) == 0)
                return;
            else
                ft_printf("Diretório inexistente\n");
        }
    }
}
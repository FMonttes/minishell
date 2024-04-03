/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:08:20 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/03 13:31:34 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd(char *input) 
{
    char *cmd;
    
    cmd = strq(input, "pwd");
    if (ft_strncmp(cmd, "pwd", ft_strlen("pwd")) == 0
    && count_quotes(input) % 2 == 0) 
    {
        char *current_directory = (char *)malloc(100000 * sizeof(char));
        if (current_directory != NULL) 
        {
            if (getcwd(current_directory, 100000) != NULL) 
                printf("%s\n", current_directory);
             else
                perror("Erro ao obter o diretório de trabalho atual");
            free(current_directory);

        }
    }
    else
        printf("syntax error\n");
}

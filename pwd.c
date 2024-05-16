/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:08:20 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/16 13:21:58 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd(char *input)
{
    char *cmd;
    char *current_directory;
    char **args;

    cmd = strq(input, "pwd");
    int pid = fork();
    args = ft_split(input, ' ');
    if (pid == 0)
    {
        if (ft_strncmp(args[0], "pwd", ft_strlen(args[0])) == 0 && count_quotes(input) % 2 == 0)
        {
            redirect(ft_split(input, ' '));
            heredoc(ft_split(input, ' '));
            current_directory = getcwd(NULL, 0);
            // char *current_directory = (char *)malloc(100000 * sizeof(char));

            if (current_directory)
            {
                ft_printf("%s\n", current_directory);
                free(current_directory);
            }
            else
                perror("Erro ao obter o diretório de trabalho atual");
            exit(1);
        }
        // else
        //     ft_printf("syntax error\n");
    }
    waitpid(pid, NULL, 0);
}

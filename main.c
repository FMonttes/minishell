/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/09 17:03:04 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
    char    *input;
    int i;

   while (1)
    {
        input = readline("minishell: ");
        if (strncmp(input, "export", ft_strlen("export")) == 0)
          creat_env(input, env);
        if (strncmp(input, "unset", ft_strlen("unset")) == 0)
          unset(input, env);
        print_env(input, env);
        //pwd(input);
        //echo(input);
        //cd(input);
        //if (ft_exit(input) == 0); //vai dar leak
          //  break; 
        free(input);
    }
}
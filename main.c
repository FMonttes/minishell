/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/03 16:31:32 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
    char    *input;

   while (1)
    {
        input = readline("minishell: ");
        //print_env(input, env);
        //pwd(input);
        //echo(input);
        //cd(input);
        if (ft_exit(input) == 0); //vai dar leak
            break;
        free(input);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/11 15:27:47 by fmontes          ###   ########.fr       */
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
        check_builtin(input, env);
        if (hidenp("exit", input) == 1)
        {
            if (ft_exit(input) == 0) //vai dar leak
              break;
        }
        free(input);
    }
}
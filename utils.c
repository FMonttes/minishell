/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:25:32 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/11 15:27:38 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int hidenp(char *cmd, char *input)
{
	int i = 0;
	int j = 0;
	
		while (input[j] && cmd[i])
		{
			if (input[j] == cmd[i])
				i++;
			j++;
		}
		if (cmd[i] == '\0')
			return 1;
		else
			return 0;
}

void    check_builtin(char *input, char **env)
{
    if (hidenp("export", input) == 1)
          creat_env(input, env);
        else if (hidenp("unset", input) == 1)
          unset(input, env);
        else if (hidenp("env", input) == 1)
          print_env(input, env);
        else if (hidenp("pwd", input) == 1)
          pwd(input);
        else if (hidenp("echo", input) == 1)
          echo(input);
        else if (hidenp("cd", input) == 1)
          cd(input);
}
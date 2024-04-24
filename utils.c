/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:25:32 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/19 13:32:03 by fmontes          ###   ########.fr       */
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

int   check_builtin(char *input, char **env)
{
    if (hidenp("export", input) == 1)
      {
        creat_env(input, env);
        return 1;
      }
      else if (hidenp("unset", input) == 1)
      {
          unset(input, env);
          return 1;
      }
      else if (hidenp("env", input) == 1)
      {
          print_env(input, env);
          return 1;
      }
      else if (hidenp("pwd", input) == 1)
      {
          pwd(input);
          return 1;
      }
      else if (hidenp("echo", input) == 1)
        {
          echo(input);
          return 1;
        }
      else if (hidenp("cd", input) == 1)
        {
          cd(input);
          return 1;
        }
    return 0;
}
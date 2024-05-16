/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:47:29 by felperei          #+#    #+#             */
/*   Updated: 2024/05/16 13:21:36 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_command(char **words, char *command)
{
  int i;
  i = 0;
  while (words[i])
  {

    command = words[i];
    i++;
  }
  return (command);
}

char **get_params(char *input, char **params, char **words, char *command)
{

  int i;
  i = 0;
  int j;
  j = 0;
  params = ft_split(input, ' ');
  words = (char **)malloc(sizeof(char *) * 100);
  while (params[i])
  {
    if (ft_strchr(params[i], '|'))
      i++;
    else if (ft_strchr(params[i], '<'))
      i++;
    else if (ft_strchr(params[i], '>'))
      i++;
    words[j] = params[i];
    ft_printf("words[%d]: %s\n", j, words[j]);
    i++;
    j++;
  }
  command = get_command(words, command);
  return (words);
}

int validate_path_with_command(char *path, char *command)
{
  int i;
  i = 0;
  while (path[i])
  {
    if (path[i] == command[0])
    {
      return (1);
    }
    i++;
  }
  return (0);
}

char **get_path(void)
{
  int x;
  int i;
  char *path;
  char **paths;
  x = 0;

  path = getenv("PATH");
  paths = ft_split(path, ':');

  x = 0;
  while (paths[x])
  {
    int i = 0;
    while (paths[x][i])
    {
      i++;
    }
    paths[x][i] = '/';
    paths[x][i + 1] = '\0';
    ft_printf("%s\n", paths[x]);

    x++;
  }

  return (paths);
}

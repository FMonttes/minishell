/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:33:30 by fmontes           #+#    #+#             */
/*   Updated: 2024/06/05 11:24:01 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*strq(char *input)
{
	int		i;
	int		x;
	char	*cmd;

	i = 0;
	x = 0;
	cmd = malloc(ft_strlen(input) + 1);
	while (input[i])
	{
		if (input[i] == 39 || input[i] == 34)
			i++;
		else
			cmd[x++] = input[i++];
	}
	cmd[x] = '\0';
	return (cmd);
}

void	print_env(char *input, t_env *env)
{
	t_env	*current;

	current = env;
	if (count_quotes(input) % 2 == 0)
	{
		if (strncmp(input, "env", ft_strlen("env")) == 0)
		{
			while (current)
			{
				ft_printf("%s\n", current->env_var_s);
				current = current->next;
			}
		}
	}
	else
		ft_printf("invalid syntax\n");
}

void	redirect_env_loop(char **args, int fd, t_env *env)
{
	int		i;
	t_env	*current;

	while (args[i])
	{
		i = 0;
		if (ft_strncmp(args[i], ">", ft_strlen(args[i])) == 0)
		{
			args[i] = NULL;
			fd = open(args[i + 1], O_WRONLY, O_CREAT, O_APPEND, 0666);
		}
		i++;
	}
	current = env;
	while (current)
	{
		write(fd, ft_strjoin(current->env_var_s, "\n"),
			ft_strlen(ft_strjoin(current->env_var_s, "\n")));
		current = current->next;
	}
	close(fd);
}

void	redirect_env(char *input, t_env *env)
{
	int		fd;
	char	**args;

	fd = 0;
	args = ft_split(input, ' ');
	if (ft_strncmp(args[0], "env", ft_strlen(args[0])) == 0)
	{
		redirect_env_loop(args, fd, env);
	}
	free_args(args);
}

void	env_command(char *input, t_env *env)
{
	char	**args;

	args = ft_split(input, ' ');
	if (ft_strncmp(args[0], "env", ft_strlen(args[0])) == 0)
	{
		print_env(input, env);
	}
	free_args(args);
}

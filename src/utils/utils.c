/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:25:32 by fmontes           #+#    #+#             */
/*   Updated: 2024/06/05 12:22:47 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_word *data, t_env *env)
{
	if (hidenp("cd", data->word) == 1)
	{
		cd(data);
		return (0);
	}
	else if (hidenp("echo", data->word) == 1)
	{
		echo_command(data);
		return (0);
	}
	else if (hidenp("export", data->word) == 1)
	{
		export_command(data, env);
		return (0);
	}
	else if (hidenp("exit", data->word) == 1)
	{
		ft_exit(data);
		exit(0);
	}
	else if (is_builtin2(data, env) == 0)
		return (0);
	else
		return (1);
}

int	is_builtin2(t_word *data, t_env *env)
{
	if (hidenp("unset", data->word) == 1)
	{
		unset_command(data, env);
		return (0);
	}
	if (hidenp("env", data->word) == 1)
	{
		env_command(data->word, env);
		return (0);
	}
	else if (hidenp("pwd", data->word) == 1)
	{
		pwd(data);
		return (0);
	}
	else
		return (1);
}

void	free_list(t_word *data)
{
	t_word	*tmp;

	while (data)
	{
		tmp = data;
		data = data->next;
		free(tmp->word);
		free(tmp);
	}
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->env_var_s);
		free(tmp);
	}
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

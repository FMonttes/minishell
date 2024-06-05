/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:50:02 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 11:11:21 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}

void	ft_lstadd_back(t_word **lst, t_word *new)
{
	t_word	*last_node;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last_node = *lst;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
	}
	return ;
}

t_word	*ft_lstnew(char *input)
{
	t_word	*data;

	data = malloc(sizeof(t_word));
	if (!data)
		return (NULL);
	data->word = input;
	data->flag = 0;
	data->i = 0;
	data->fd[1] = dup(1);
	data->fd[0] = dup(0);
	data->next = NULL;
	data->status = -1;
	data->pid = 0;
	data->cmds = NULL;
	return (data);
}

char	**fill_list(t_word *data)
{
	int		i;
	int		z;
	char	**ret;
	t_word	*current;

	current = data;
	z = 0;
	i = 0;
	while (current && current->flag == WORD)
	{
		i++;
		current = current->next;
	}
	ret = malloc(sizeof(char *) * i + 1);
	current = data;
	while (z < i)
	{
		ret[z] = ft_strdup(current->word);
		z++;
		current = current->next;
	}
	ret[z] = NULL;
	return (ret);
}

void	wait_cmds(t_word *node)
{
	t_word				*aux;
	extern unsigned int	g_exit_status;

	if (!node)
		return ;
	aux = node;
	while (node)
	{
		if (node->pid != 0)
			waitpid(node->pid, &(node->status), 0);
		if (WIFEXITED(aux->status))
			g_exit_status = WEXITSTATUS(aux->status);
		node = node->next;
	}
	return ;
}

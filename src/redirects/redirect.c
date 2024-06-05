/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <felipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:02:26 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 18:39:52 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int loop_implement_redir(t_word *current, t_word *head, int fd_in)
{
    while (current && current->flag != PIPE)
    {
        if (current->flag == RDIN)
        {
            if (access(current->next->word, F_OK | R_OK) != -1)
            {
                fd_in = open(current->next->word, O_RDONLY);
                if (fd_in == (-1))
                {
                    perror("open");
                    return (-2);
                }
                head->fd[0] = fd_in;
            }
            else
            {
                printf("Error: No such file as '%s'\n", current->next->word);
                return (-1);
            }
        }
        else if (current->flag == HDOC)
            head->fd[0] = heredoc(current);
        current = current->next;
    }
    return (0);
}

int loop_redir_in(t_word *data, t_word *head, int fd_in)
{
    t_word *current;

    current = data;
    return loop_implement_redir(current, head, fd_in);
}

int redir_out(t_word *data)
{
    t_word *head;
    int fd_out;

    head = data;
    while (head && head->flag != WORD)
        head = head->next;
    while (data && data->flag != PIPE)
    {
        if (data->flag == RDOUT)
        {
            fd_out = open(data->next->word, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd_out == -1)
            {
                perror("open");
                return (-1);
            }
            head->fd[1] = fd_out;
        }
        data = data->next;
    }
    return (0);
}

int redir_in(t_word *data)
{
    t_word *head;
    int fd_in;

    dup2(data->fd[1], STDOUT_FILENO);
    fd_in = -1;
    head = data;
    while (head && head->flag != WORD)
        head = head->next;
    return loop_redir_in(data, head, fd_in);
}

int do_redir(t_word *data)
{
    if (!data)
        return (0);
    if (redir_in(data) == -1 || redir_out(data) == -1 || append(data) == -1)
        return (-1);
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:59:31 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/21 15:55:03 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word *creat_list(char *input)
{
    t_word *data = NULL;
    t_word *head = NULL;
    char **split;
    int i = 0;

    split = ft_split(input, ' ');
    head = ft_lstnew(split[i]);
    data = head;

    while (split[++i])
    {
        data->next = ft_lstnew(split[i]);
        data = data->next;
    }

    return head;
}

t_word *ft_lstnew(char *input)
{
    t_word *data = (t_word *)malloc(sizeof(t_word));
    if (!data)
        return NULL;

    data->word = input;
    data->fd_in = 0;
    data->fd_out = 0;
    data->flag = 0;
    data->next = NULL;

    return data;
}

void print_list(t_word *head)
{
    t_word *current = head;
    while (current)
    {
        printf("word: %s\n", current->word);
        current = current->next;
    }
}

int main()
{
    char input[] = "Hello world! This is a test.";
    t_word *list = creat_list(input);

    // Print the list
    print_list(list);

    // Clean up (free memory)
    t_word *current = list;
    while (current)
    {
        t_word *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
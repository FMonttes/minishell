/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/16 15:25:15 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int count_quotes(char *input)
{
    int i;
    int quotes;

    i = 0;
    quotes = 0;
    while (input[i])
    {
        if (input[i] == 39 || input[i] == 34)
            quotes++;
        i++;
    }
    return quotes;
}

/*void echo(char *input)
{
    int i;
    char *cmd;
    char *cmd2;

    i = 2;
    cmd = strq(input, "echo");
    cmd = remove_extra_spaces(cmd);
    cmd2 = strq(input, "echo -n");
    cmd2 = remove_extra_spaces(cmd2);
    char **arg = ft_split(input, ' ');
    if (count_quotes(input) % 2 == 0)
    {
        if (ft_strncmp("echo", arg[0], ft_strlen(arg[0])) == 0 &&
            ft_strncmp("-n", arg[1], ft_strlen("-n")) == 0)
        {
            while (arg[i])
            {
                if (arg[i + 1] == NULL)
                    ft_printf("%s", arg[i++]);
                else
                    printf("%s ", arg[i++]);
            }
        }
        else if (ft_strncmp(arg[0], "echo", ft_strlen(arg[0])) == 0)
        {
            printf("%s\n", cmd + 5);
        }
    }
    else
        printf("invalid syntax\n");
}*/

static void maintain_double_quotes_spaces(char **str, int *i, int *j)
{
    if ((*str)[*i] && (*str)[*i] == DOUBLE_QUOTES)
    {
        (*i)++;
        while ((*str)[*i] && (*str)[*i] != DOUBLE_QUOTES)
        {
            (*str)[*j] = (*str)[*i];
            (*j)++;
            (*i)++;
        }
        (*i)++;
        (*str)[(*j)++] = ' ';
    }
}

char *remove_extra_spaces(char *str, int maintain_double_q_spaces)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (maintain_double_q_spaces)
            maintain_double_quotes_spaces(&str, &i, &j);
        while (str[i] && (str[i] != ' ' && str[i] != '\t'))
        {
            if (str[i] == DOUBLE_QUOTES && maintain_double_q_spaces)
                maintain_double_quotes_spaces(&str, &i, &j);
            str[j] = str[i];
            if (str[i + 1] == ' ' || str[i + 1] == '\t')
                str[++j] = ' ';
            j++;
            i++;
        }
    }
    if (str[j - 1] == ' ' || str[j - 1] == '\t')
        j--;
    str[j] = '\0';
    return (str);
}

void echo_command(char *input)
{
    char **args;
    args = ft_split(input, ' ');
    int pid = fork();
    if (pid == 0)
    {
        redirect(ft_split(input, ' '));
        heredoc(ft_split(input, ' '));
        if (!args[1] && ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0)
        {
            ft_printf("\n");
        }
        else if (ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0 && ft_strncmp("-n", args[1], ft_strlen(args[1])) == 0)
        {
            ft_printf("%s", remove_extra_spaces(input, 1) + 8);
        }
        else if (ft_strncmp("echo", args[0], ft_strlen(args[0])) == 0)
        {
            ft_printf("%s\n", remove_extra_spaces(input, 1) + 5);
        }
        exit(1);
    }
    wait(NULL);
}
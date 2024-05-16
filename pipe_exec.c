/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:25:51 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/16 16:47:38 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int verifica_pipe(char *input) {
    int dentro_das_aspas = 0;
    char *ptr = input;
    int pipe_fora_das_aspas = 0;

    while (*ptr != '\0') {
        if (*ptr == '"') {
            dentro_das_aspas = 1 - dentro_das_aspas;
        } else if (*ptr == '|' && dentro_das_aspas) {
            return 1;
        } else if (*ptr == '|' && !dentro_das_aspas) {
            pipe_fora_das_aspas = 1;
        }
        ptr++;
    }

    if (pipe_fora_das_aspas) {
        return (2);
    }

    return 0;
}*/

static void save_output(int /* current_fd */, char **commands, int *fd, t_env *env)
{
    char **args = ft_split(*commands, ' ');
    redirect(args);
    heredoc(args);
    // if (bash_execs(*commands, env) == 0)
    //     exit(EXIT_FAILURE);
    // else
    //     printf("minishell: command not found: %s\n", first_word(*commands));
    if (check_builtin(*commands, env) == 1)
    {
        // char **args = ft_split(*commands, ' ');
        // heredoc(args);
        echo_command(*commands);
        pwd(*commands);
        redirect_env(*commands, env);
    }
    /* dup2(current_fd, STDIN_FILENO); */
    if (*(commands + 1) != NULL)
        dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    char **args2 = ft_split(getenv("PATH"), ':');
    int i = 0;
    while (args2[i])
    {
        char *cmd = ft_strjoin(args2[i], "/");
        if ((execve(ft_strjoin(cmd, first_word(*commands)),
                    args, env->environ)) == -1)
            ;
        i++;
    }
    exit(1);
}

static void exec_outputs(t_env *env, char **commands, int *fd, __pid_t pid)
{
    int *pids;
    int i = 0;
    int j;
    int current_fd = 0;
    while (commands[i])
        i++;
    j = i;
    pids = (int *)malloc(sizeof(int) * i);
    i = 0;
    while (*commands != NULL)
    {
        pipe(fd);
        pid = fork();
        pids[i++] = pid;
        if (pid == 0)
            save_output(0, commands, fd, env);
        close(fd[1]);
        dup2(fd[0], 0);
        close(fd[0]);
        commands++;
    }
    i = 0;
    while (i < j)
        waitpid(pids[i++], NULL, 0);
}
void ft_pipe(char *input, t_env *env)
{
    char **commands;
    __pid_t pid;
    int fd[2];
    pid = fork();
    if (pid == 0)
    {
        commands = ft_split(input, '|');
        exec_outputs(env, commands, fd, pid);
        exit(1);
    }
    waitpid(pid, NULL, 0);
}

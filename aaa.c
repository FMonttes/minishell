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
    data->flag = 0;
    data->next = NULL;

    return data;
}

void token(t_word *data)
{
    t_word *current = data;
    int i;

    while (current && current->word)
    {
        i = 0;
        while (current->word[i])
        {
            if (current->word[i] == '|')
                current->flag = PIPE;
            else if (current->word[i] == '<' && current->word[i + 1] == '<')
                current->flag = HDOC;
            else if (current->word[i] == '>' && current->word[i + 1] == '>')
                current->flag = APPEND;
            else if (current->word[i] == '<')
                current->flag = RDIN;
            else if (current->word[i] == '>')
                current->flag = RDOUT;
            else
                current->flag = WORD;
            i++;
        }
        current = current->next;
    }
}

void print_list(t_word *head)
{
    t_word *current = head;
    t_tkn token_type;
    while (current)
    {
        printf("%d: %s\n", current->flag, current->word);
        current = current->next;
    }
}

int main()
{
    extern char **environ;
    char *input;
    int fd[2];
    t_env *env;
    t_word *list;
    env = init_env(environ);
    env->environ = environ;
    while (1)
    {
        input = readline("\x1b[1;36mminishell\u2192\x1b[0m ");
        input = ft_strtrim(join_expand(input, env), "     ");
        add_history(input);
        list = creat_list(input);
        token(list);

        bash_execs(list, env);
        print_list(list);
        // Clean up (free memory)
    }
    return 0;
}

/* executor()
{
    int has_pipe;

    ft_pipe();
    has_pipe = ft_strchr_int(data->raw_cmd, '|');
    while(prompt)
    {
        if(do_redir(prompt))
            return ;
        if (has_pipe)
            exec_pipe();
        else
            bash_exec();
        prompt = next_pipe();
    }
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:16:18 by fmontes           #+#    #+#             */
/*   Updated: 2024/05/23 12:31:20 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *join_expand(char *input, t_env *env)
{
    int i = 0;
    char *ret = ft_strdup("");
    char **args = ft_split(input, ' ');
    while (args[i])
    {
        if (ft_strchr(args[i], '$'))
        {
            ret = ft_strjoin(ret, getenv(args[i] + 1));
            ret = ft_strjoin(ret, " ");
            i++;
            continue;
        }
        ret = ft_strjoin(ret, args[i]);
        ret = ft_strjoin(ret, " ");
        i++;
    }
    return (ret);
}

/*int main(int ac, char **av, char **env)
{

    t_env *envp = init_env(env);
    char *ret = join_expand("cd $HOME | echo $LOGNAME", envp);
    ret = ft_strtrim(ret, "     ");
    printf("%s\n", ret);
}*/
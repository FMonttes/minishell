/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:40:28 by fmontes           #+#    #+#             */
/*   Updated: 2024/04/02 16:30:58 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    put_strq(char *input)
{
    int     i;
    
    i = 0;
    while (input[i])
    {
        if (input[i] == 39 || input[i] == 34)
            i++;
        else
            printf("%c", input[i++]);
    }
}

int     count_quotes(char *input)
{
    int     i;
    int     quotes;

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

void   echo(char *input)
{
    int     i;

    i = 0;
    if (count_quotes(input) % 2 == 0)
    {
      
          if (ft_strncmp(input, "echo -n", 7) == 0)
                put_strq(input + 8);
            else if (input)
            {
                put_strq(input + 5);
                printf("\n");
            }
    }
    else
        printf("invalid syntax\n");
}

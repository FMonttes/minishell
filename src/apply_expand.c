/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felperei <felperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:29:46 by felperei          #+#    #+#             */
/*   Updated: 2024/06/05 14:00:12 by felperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	apply_expand(t_word *prompt, t_env *env)
{
	char	*temp;

	temp = NULL;
	while (prompt)
	{
		temp = prompt->word;
		prompt->word = expand_word(prompt->word, env);
		prompt->word = search_and_replace_customized(prompt->word, '@', '$');
		free(temp);
		prompt = prompt->next;
	}
}

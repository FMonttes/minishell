#include "minishell.h"

int	heredoc_loop(char *line, t_word *data, int fd[])
{
	while (1)
	{
		line = readline(">");
		if (!line || ft_strncmp(data->next->word, line, ft_strlen(line) + 1) == 0)
			break;
		else if (line)
		{
			write (fd[1], line, ft_strlen(line));
			write (fd[1], "\n", 1);
			free(line);
		}
	}
	if (line)
		free(line);
}

int	heredoc(t_word *data)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		return (-1);
	line = NULL;
	heredoc_loop(line, data, fd);
	close (fd[1]);
	return (fd[0]);
}

int append(t_word *data)
{
	t_word *current;
	current = data;
	int fd_out;
	
	while (current && current->flag != WORD)
		current = current->next;
	while (current && current->flag != PIPE)
	{
		if (current->flag == APPEND)
		{		
				fd_out = open(current->next->word, O_WRONLY | O_CREAT | O_APPEND, 0644);
				if (fd_out == -1)
				{
					perror("open");
					return (-1);
				}
					current->fd[1] = fd_out;
					dup2(current->fd[1], STDIN_FILENO);
		}
		current = current->next;
	}
	return (0);
}

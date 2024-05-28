#include "minishell.h"

int	write_in_stdin(int flag, char *joined, char **args)
{
	if (flag)
	{
		int fd[2];
		__pid_t	pid;

		pipe(fd);
		pid = fork();
		if (pid == 0)
		{	
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);

			if (execve(ft_strjoin("/bin/", args[0]), args, NULL) == -1)
			{
				ft_printf("minishell: command not found: %s\n", args[0]);
				exit(EXIT_FAILURE);
			}
		}
		close(fd[0]);
		write(fd[1], joined, ft_strlen(joined));
		close(fd[1]);
		waitpid(pid, NULL, 0);
		return (1);
	}
	return (0);
}

int	heredoc(char **args, t_env *env)
{
	int		i;
	int		input_fd;
	int		output_fd;
	int		flag = 0;
	char	*joined = ft_strdup("");
	char	*delimitador;
	char	*input;

	flag = 0;
	joined = ft_strdup("");
	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "<<", ft_strlen(args[i])) == 0)
		{
			args[i] = NULL;
			delimitador = args[i + 1];
			while (1)
			{
				input = readline(">");
				if (ft_strncmp(input, delimitador, ft_strlen(delimitador)) == 0)
				{
					free(input);
					break;
				}
				joined = ft_strjoin(joined, input);
				joined = ft_strjoin(joined, "\n");
				free(input);
			}
			flag = 1;
		}
		i++;
	}
	return (write_in_stdin(flag, joined, args));
}

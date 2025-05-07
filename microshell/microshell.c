/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:08:40 by aelaaser          #+#    #+#             */
/*   Updated: 2025/05/07 16:02:06 by aelaaser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
int err(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}
int cd(char **argv, int i)
{
	if (i != 2)
		return (err("error: cd: bad arguments\n"));
	else if (chdir(argv[1]) == -1)
		return (err("error: cd: cannot change directory to "), err(argv[1]), err("\n"));
	else
		return (0);
}
int exec(char **argv, char **envp, int i)
{
	int fd[2];
	int pid;
	int status;
	int has_pipe;

	has_pipe = argv[i] && !strcmp(argv[i], "|");
	if (has_pipe && pipe(fd) == -1)
		return (err("fatel error\n"));
	pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (err("fatel error\n"));
		execve(*argv, argv, envp);
		return (err("error: cannot execute "), err(*argv), err("\n"));
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (err("fatel error\n"));
	return(WIFEXITED(status));
}

int main(int argc, char **argv, char **envp)
{
	int i;
	int status;

	i = 0;
	status = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd(argv, i);
			else if (i)
				status = exec(argv, envp, i);
		}
	}
	return (status);
}

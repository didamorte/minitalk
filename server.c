/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <diogribe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:25:49 by diogribe          #+#    #+#             */
/*   Updated: 2025/03/26 14:32:39 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

typedef struct	s_message {
	char	*str;
	size_t	len;
	size_t	max_len;
}				t_message;

static t_message	g_msg = {NULL, 0, 0};

void	add_char_to_buffer(char c)
{
	if (g_msg.len + 1 >= g_msg.max_len)
	{
		g_msg.max_len += 1024;
		g_msg.str = ft_realloc(g_msg.str, g_msg.len, g_msg.max_len);
		if (!g_msg.str)
		{
			ft_printf("Error: Memory allocation failed.\n");
			exit(1);
		}
	}
	g_msg.str[g_msg.len++] = c;
	g_msg.str[g_msg.len] = '\0';
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char		char_byte;
	static int		bit_count;
	static pid_t	client_pid;

	(void)context;
	client_pid = info->si_pid;
	char_byte = (char_byte << 1) | (sig == SIGUSR2);
	bit_count++;
	if (bit_count == 8)
	{
		if (char_byte == '\0')
		{
			ft_printf("%s\n", g_msg.str);
			free(g_msg.str);
			g_msg = (t_message){NULL, 0, 0};
			kill(client_pid, SIGUSR1);
		}
		else
		{
			add_char_to_buffer(char_byte);
			kill(client_pid, SIGUSR1);
		}
		char_byte = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server ON\nServer PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

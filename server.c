/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:25:49 by diogribe          #+#    #+#             */
/*   Updated: 2025/03/24 19:01:42 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char		char_byte = 0;
	static int		bit_count = 0;
	static pid_t	client_pid = 0;

	(void)context;
	client_pid = info->si_pid;
	char_byte = (char_byte << 1) | (sig == SIGUSR2);
	bit_count++;
	if (bit_count == 8)
	{
		if (char_byte == '\0')
		{
			write(1, "\n", 1);
		}
		else
			write(1, &char_byte, 1);
		kill(client_pid, SIGUSR1);
		char_byte = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server ON\nServer PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}

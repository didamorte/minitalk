/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <diogribe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:25:49 by diogribe          #+#    #+#             */
/*   Updated: 2025/03/23 02:33:03 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char		char_byte = 0;
	static int		bit_count = 0;
	static pid_t	client_pid = 0;

	(void)context;
	// Se for um novo cliente, atualiza o PID
	if (client_pid == 0 || client_pid != info->si_pid)
		client_pid = info->si_pid;
	
	// Monta o byte: SIGUSR2 representa 1, SIGUSR1 representa 0
	char_byte = (char_byte << 1) | (sig == SIGUSR2);
	bit_count++;

	// Quando completamos 8 bits (1 byte)
	if (bit_count == 8)
	{
		if (char_byte == '\0')
		{
			write(1, "\n", 1);
			usleep(50);
			kill(client_pid, SIGUSR1);
			client_pid = 0;
		}
		else
		{
			write(1, &char_byte, 1);
			usleep(50);
			kill(client_pid, SIGUSR1);
		}
		// Reset para o próximo byte
		bit_count = 0;
		char_byte = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server ON\nServer PID: %d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}

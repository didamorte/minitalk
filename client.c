/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <diogribe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:25:53 by diogribe          #+#    #+#             */
/*   Updated: 2025/03/23 02:34:49 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


volatile int	g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_byte(int pid, unsigned char c)
{
	int	i;
	int	timeout;
	
	i = 8;
	// Envia os bits (do bit mais significativo ao menos)
	while(--i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2); // Envia 1
		else
			kill(pid, SIGUSR1); // Envia 0
		usleep(500);
	}
	timeout = 500; // Ajusta o timeout conforme necessário
	while (!g_ack_received && timeout--)
		usleep(50);
	if (!g_ack_received)
	{
		write(2, "Erro: Timeout ao esperar ACK do servidor.\n", 43);
		exit(1);
	}
	// Reseta para enviar o próximo byte
	g_ack_received = 0;
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (ac != 3)
	{
		write(2, "Uso: ./client <PID> <mensagem>\n", 31);
		return (1);
	}
	pid = ft_atoi(av[1]);

	// Configura o handler para receber ACK (SIGUSR1)
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sa.sa_handler = ack_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);

	// Envia a mensagem caractere por caractere
	i = 0;
	while (av[2][i])
	{
		send_byte(pid, av[2][i]);
		i++;
	}
	// Envia o terminador de string
	send_byte(pid, '\0');

	write(1, "Mensagem enviada!\n", 18);
	return (0);
}

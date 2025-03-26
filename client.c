/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <diogribe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:25:53 by diogribe          #+#    #+#             */
/*   Updated: 2025/03/26 14:36:50 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile int	g_message_received = 0;

void	confirmation_handler(int sig)
{
	(void)sig;
	g_message_received = 1;
}

void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 8;
	g_message_received = 0;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
	while (!g_message_received)
			pause();
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
		return (1);
	sa.sa_handler = confirmation_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	i = -1;
	while (av[2][++i] != '\0')
		send_char(pid, av[2][i]);
	send_char(pid, '\0');
	ft_printf("Message sent to server PID %d!\n", pid);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:19:01 by diogribe          #+#    #+#             */
/*   Updated: 2024/10/25 14:34:16 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}

/* int main()
{
	char	str[] = "ola mundo";
	ft_bzero(str, ft_strlen(str));
	printf("vazia: %s", str);
} */
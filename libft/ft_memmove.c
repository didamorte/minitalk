/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:26:24 by diogribe          #+#    #+#             */
/*   Updated: 2024/10/25 14:50:47 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*t_dest;
	const unsigned char	*t_src;

	t_dest = (unsigned char *)dest;
	t_src = (const unsigned char *)src;
	if (t_dest > t_src)
		while (n--)
			t_dest[n] = t_src[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/* int main()
{
	char	*str = "ola mundo";
	char	dest[20];
	ft_memmove(dest, str, ft_strlen(str));
	printf("%s", dest);
} */
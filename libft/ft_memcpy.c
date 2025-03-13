/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:14:20 by diogribe          #+#    #+#             */
/*   Updated: 2024/10/25 17:39:34 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*t_dest;
	unsigned char	*t_src;

	if (!(dest || src))
		return (dest);
	t_dest = (unsigned char *)dest;
	t_src = (unsigned char *)src;
	while (n)
	{
		*t_dest++ = *t_src++;
		n--;
	}
	return (dest);
}

/* int main()
{
	char	*str = "ola mundo";
	char	dest[20];
	ft_memcpy(dest, str, ft_strlen(str));
	printf("%s", dest);
} */
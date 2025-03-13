/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:09:07 by diogribe          #+#    #+#             */
/*   Updated: 2024/10/25 17:45:09 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n)
	{
		if (*ptr == (unsigned char)c)
			return (&*ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

/* int main()
{
	char	str[] = "ola mundo";
	printf("%s", (char *)ft_memchr(str, 'm', ft_strlen(str)));
} */
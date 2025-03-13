/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:00:03 by diogribe          #+#    #+#             */
/*   Updated: 2024/10/25 18:04:45 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)&*s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)&*s);
	return (NULL);
}

/* int main()
{
	char	*str = "ola mundo";
	printf("%s", ft_strchr(str, 'm'));
} */
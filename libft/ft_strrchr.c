/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:01:53 by diogribe          #+#    #+#             */
/*   Updated: 2024/10/25 14:37:35 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*lc;

	lc = NULL;
	while (*s)
	{
		if (*s == (char)c)
			lc = (char *)&*s;
		s++;
	}
	if (*s == (char)c)
		lc = (char *)&*s;
	return (lc);
}

/* int main()
{
	char	*str = "ola mano";
	printf("%s", ft_strchr(str, ' '));
} */
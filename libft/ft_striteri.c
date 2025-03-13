/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogribe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:23:16 by diogribe          #+#    #+#             */
/*   Updated: 2024/10/28 11:54:35 by diogribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, s);
		i++;
		s++;
	}
}
/* void to_lowercase(unsigned int i, char *c) 
{
	if (i % 2 == 0)
		*c = ft_tolower(*c);
}

int main()
{
	char	str[] = "OLA MUNDO";
	ft_striteri(str, to_lowercase);
	printf("%s", str);
} */
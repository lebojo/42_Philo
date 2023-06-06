/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:43:11 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 04:32:29 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../proto.h"

int	zz_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (zz_strlen(s1) + 1));
	if (!res)
		return (0);
	while (i < (int)zz_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	memset(ptr, '\0', size * count);
	return (ptr);
}
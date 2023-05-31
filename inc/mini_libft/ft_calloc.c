/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:30:11 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/31 02:28:17 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../proto.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	memset(ptr, '\0', size * count);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 05:08:51 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 07:36:52 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	error(char *str)
{
	printf("\033[0;31m[ERROR] \033[0m %s\n", str);
	return (1);
}

int	info(char *str)
{
	printf("\e[0;32m[PHILO] \033[0m%s\n", str);
	return (1);
}

void	p_state(unsigned long int time, int philo, enum e_s s)
{
	philo++;
	// printf("\e[0;32m[PHILO] \033[0m");
	// if (s == Thinking)
	// 	printf("%lums %i is thinking\n", time, philo);
	// if (s == Eating)
	// 	printf("%lums %i is Eating\n", time, philo);
	// if (s == Fork)
	// 	printf("%lums %i take a fork\n", time, philo);
	// if (s == Sleeping)
	// 	printf("%lums %i is sleeping\n", time, philo);
	// if (s == Dead)
	// 	printf("%lums %i died\n", time, philo);
}

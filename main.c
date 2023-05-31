/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:16:15 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/31 05:24:23 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	invalid_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	(void)argv;
	return (0);
}

void	*routine(void *philo)
{
	t_philo	p;

	p = *(t_philo *)philo;
	philo_state(2, p.id, p.state);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_time	time;
	int		i;

	if (invalid_args(argc, argv))
		return (error("Args"));
	init_data(&data, &time, argc, argv);
	i = -1;
	while (++i < data.nb_philo)
	{
		data.philo[i].time = &time;
		data.philo[i].has_fork = 1;
		data.philo[i].id = i + 1;
		data.philo[i].state = 'T';
		pthread_create(&data.philo[i].tr, NULL, &routine, &data.philo[i]);
		pthread_join(data.philo[i].tr, NULL);
	}
	return (0);
}

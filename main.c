/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:16:15 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/02 05:23:01 by jchapell         ###   ########.fr       */
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
	t_philo			p;
	int				tmp;

	p = *(t_philo *)philo;
	while (p.state != 'D')
	{
		if (p.state == 'T')
			can_eat(&p);
		if (p.state == 'S')
		{
			tmp = get_now();
			philo_state(get_now(), p.id, p.state);
			usleep(p.time->sleep / 1000);
			if (p.state != 'D')
				p.state = 'T';
		}
		philo_state(get_now(), p.id, p.state);
	}
	return (0);
}

void	*the_game_master(void *data)
{
	int		i;
	t_data	d;

	d = *(t_data *)data;
	i = 0;
	while (1)
	{
		if (i > d.nb_philo)
			i = 0;
		if (d.philo[i].last_eat >= d.time.die
			&& d.philo[i].state != 'E')
		{
			clean_exit(&d);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	int				i;
	pthread_t		master;

	if (invalid_args(argc, argv))
		return (error("Args"));
	init_data(&data, &data.time, argc, argv);
	i = -1;
	while (++i < data.nb_philo - 1)
		create_philo(&data, &data.philo[i], &data.philo[i + 1], i);
	create_philo(&data, &data.philo[i], &data.philo[0], i);
	i = 0;
	pthread_create(&master, NULL, &the_game_master, &data);
	while (1)
		;
	return (0);
}

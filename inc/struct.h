/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 03:29:32 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/06 23:46:39 by jordan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "proto.h"

enum e_s
{
	Eating,
	Sleeping,
	Thinking,
	Dead,
	Fork,
	Fork2
};

typedef struct s_time
{
	int	eat;
	int	die;
	int	sleep;
	int	must_eat;
}	t_time;

typedef struct s_philo
{
	int					id;
	unsigned long int	last_eat;
	int					nb_philo;
	t_time				*t;
	pthread_mutex_t		*fork;
	pthread_mutex_t		*next_fork;
	pthread_mutex_t		*l;
	enum e_s			state;
	pthread_t			tr;
	pthread_t			life;
	unsigned long int	start;
	unsigned long int	*gs;
}	t_philo;

typedef struct s_data
{
	t_time				time;
	t_philo				*p;
	pthread_mutex_t		*forks;
	pthread_mutex_t		lock;
	int					nb_philo;
	unsigned long int	start;
}	t_data;

#endif
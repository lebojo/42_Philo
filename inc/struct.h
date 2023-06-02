/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 03:19:22 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/02 01:43:32 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "proto.h"

typedef struct s_time
{
	int				eat;
	int				die;
	int				sleep;
	int				end;
	struct timeval	start;
	struct timeval	now;
}	t_time;

typedef struct s_philo
{
	char			state;
	int				id;
	int				last_eat;
	int				*forks;
	int				*max;
	pthread_mutex_t	*lock;
	pthread_t		tr;
	t_time			*time;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				*forks;
	pthread_mutex_t	lock;
	t_time			time;
	t_philo			*philo;
}	t_data;

#endif
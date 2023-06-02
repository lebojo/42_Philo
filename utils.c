/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:36:11 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/02 01:56:53 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	zz_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*add_str(char *s1, char *s2, int f)
{
	char	*res;
	int		i;
	int		ii;

	res = malloc(zz_strlen(s1) + zz_strlen(s2) + sizeof(char));
	i = -1;
	ii = 0;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[ii])
		res[i++] = s2[ii++];
	res[i] = '\0';
	if (f == 1)
		free(s1);
	else if (f == 2)
		free(s2);
	else if (f == 3)
	{
		free(s1);
		free(s2);
	}
	return (res);
}

int	time_diff(struct timeval *start, struct timeval *end)
{
	gettimeofday(end, NULL);
	return ((end->tv_usec - start->tv_usec) / 1000);
}

int	get_now(t_time *time)
{
	return (time_diff(&time->start, &time->now));
}

void	take_forks(char *state, int	*f, int id, int max)
{
	if (id < max && f[id] && f[id + 1])
	{
		f[id] = 0;
		f[id + 1] = 0;
		*state = 'E';
	}
	else if (id == max && f[id] && f[0])
	{
		f[id] = 0;
		f[id + 1] = 0;
		*state = 'E';
	}
}

void	clean_exit(t_philo *p)
{
	pthread_mutex_destroy(p->lock);
	exit(info("Successfull exit!"));
}

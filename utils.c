/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jordan <jordan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 01:36:11 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/05 00:22:52 by jordan           ###   ########.fr       */
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

long int	get_now(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL))
		return (error("gettimeofday() FAILURE"));
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

long int	get_now_rel(t_philo *p)
{
	return (get_now() - p->philo_start);
}

void	clean_exit(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->nb_philo)
	{
		pthread_mutex_destroy(&d->philo[i++].fork);
	}
	exit(info("Successfull exit!"));
}

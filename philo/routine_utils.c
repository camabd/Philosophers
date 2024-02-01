/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:38:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/01 16:50:21 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
int	philo_dead(t_philo *philo)
{	
	pthread_mutex_lock(philo->data->check_status);
	if ((get_time() - philo->last_meal) > philo->t_die)
	{
		if (philo->data->status == alive)
		{
			philo->data->status = dead;
			pthread_mutex_lock(philo->data->write);
			printf("%lld %d died\n", (get_time() - philo->time), philo->pos);
			pthread_mutex_unlock(philo->data->write);
		}
		pthread_mutex_unlock(philo->data->check_status);
		return (1);
	}
	if (philo->data->status == dead)
		return (pthread_mutex_unlock(philo->data->check_status), 1);
	pthread_mutex_unlock(philo->data->check_status);
	return (0);
}
*/

int	philo_dead(t_philo *philo)
{
	if ((get_time() - philo->last_meal) > philo->t_die)
	{
		pthread_mutex_lock(philo->data->check_status);
		if (philo->data->status == alive)
		{
			philo->data->status = dead;
			pthread_mutex_lock(philo->data->write);
			printf("%lld %d died\n", (get_time() - philo->time), philo->pos);
			pthread_mutex_unlock(philo->data->write);
		}
		pthread_mutex_unlock(philo->data->check_status);
		return (1);
	}
	return (0);
}

int	print_message(t_philo *philo, char *str)
{
	if (philo_dead(philo))
		return (0);
	pthread_mutex_lock(philo->data->check_status);
	if (philo->data->status == dead)
		return (pthread_mutex_unlock(philo->data->check_status), 0);
	pthread_mutex_lock(philo->data->write);
	printf("%lld %d %s\n", (get_time() - philo->time), philo->pos, str);
	pthread_mutex_unlock(philo->data->write);
	pthread_mutex_unlock(philo->data->check_status);
	return (1);
}

int	my_usleep(t_philo *philo, long long begining, long long duration)
{
	long long	end_time;
	long long	time_of_death;

	end_time = begining + duration;
	time_of_death = philo->last_meal + philo->t_die;
	while (get_time() < end_time)
	{
		usleep(330);
		if (get_time() > time_of_death)
			return (philo_dead(philo), 0);
	}
	return (1);
}

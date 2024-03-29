/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:38:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/05 15:51:58 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_dead(t_philo *philo)
{
	if ((get_time() - philo->last_meal) > philo->t_die)
	{
		pthread_mutex_lock(philo->check_status);
		if (*(philo->status) == alive)
		{
			(*(philo->status)) = dead;
			pthread_mutex_lock(philo->write);
			printf("%lld %d died\n", ((get_time() - philo->time) \
			/ 1000), philo->pos);
			pthread_mutex_unlock(philo->write);
		}
		pthread_mutex_unlock(philo->check_status);
		return (1);
	}
	return (0);
}

int	print_message(t_philo *philo, char *str)
{
	if (philo_dead(philo))
		return (0);
	pthread_mutex_lock(philo->check_status);
	if (*(philo->status) == dead)
		return (pthread_mutex_unlock(philo->check_status), 0);
	pthread_mutex_lock(philo->write);
	printf("%lld %d %s\n", ((get_time() - philo->time) / 1000), philo->pos, str);
	pthread_mutex_unlock(philo->write);
	pthread_mutex_unlock(philo->check_status);
	return (1);
}

int	my_usleep(t_philo *philo, long duration)
{
	long long	current;
	long long	end_time;
	long long	time_of_death;

	current = get_time();
	end_time = get_time() + duration;
	time_of_death = philo->last_meal + philo->t_die;
	while (current < end_time)
	{
		usleep(330);
		current = get_time();
		if (current > time_of_death)
		{
			if (philo_dead(philo))
				return (0);
		}
	}
	return (1);
}

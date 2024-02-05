/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:28:02 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/05 15:53:23 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
1000 usec = 1 ms = approximation de temps de création d'un thread
==> usleep(1000) = 1000 microsec = 1 ms
Rqes :
- En cas de nb de philos paire, j'envoi les paires en premier et je
fais attendre les impaires:
if ((philo->nb_philos % 2 == 0) && (philo->pos % 2 != 0))
		usleep((philo->t_eat / 2)); 
- En cas de nb de philos impaire, j'envoi les impaires en premier et je
fais attendre les paires:
if ((philo->nb_philos % 2 != 0) && (philo->pos % 2 == 0))
		usleep((philo->t_eat / 2));
*/
static void	handle_departure(t_philo *philo)
{
	philo->time = philo->time + (philo->nb_philos * 1000);
	while (get_time() < philo->time)
		usleep(1000);
	philo->last_meal = get_time();
	print_message(philo, "is thinking");
	if ((philo->nb_philos % 2 == 0) && (philo->pos % 2 != 0))
		usleep((philo->t_eat / 2));
	else if ((philo->nb_philos % 2 != 0) && (philo->pos % 2 == 0))
		usleep((philo->t_eat / 2));
}

static void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("%lld %d has taken a fork\n", ((get_time() - philo->time) / 1000), \
	philo->pos);
	usleep((philo->t_die + 1000));
	printf("%lld %d died\n", ((get_time() - philo->time) / 1000), philo->pos);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}

static void	wait_after_thinking(int delay)
{
	long long	time_now;

	time_now = get_time();
	while (get_time() - time_now < delay)
		usleep(50);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	handle_departure(philo);
	if (philo->nb_philos == 1)
		return (one_philo(philo));
	while (!philo_dead(philo))
	{
		if (!take_forks(philo))
			return (NULL);
		if (!eat(philo))
			return (NULL);
		if (!sleeping(philo))
			return (NULL);
		if (!think(philo))
			return (NULL);
		wait_after_thinking(philo->sync);
	}
	return (NULL);
}

/* static void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	printf("%lld %d has taken a fork\n", (get_time() - philo->time), \
	philo->pos);
	usleep((philo->t_die + 1) * 1000);
	pthread_mutex_lock(philo->data->check_status);
	pthread_mutex_lock(philo->data->write);
	printf("%lld %d died\n", (get_time() - philo->time), philo->pos);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->data->check_status);
	pthread_mutex_unlock(philo->data->write);
	return (NULL);
}*/
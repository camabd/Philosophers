/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:28:02 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/28 12:58:18 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//1000 ms = approximation de temps de création d'un thread
//usleep(1000) = 1000 microsec = 1 ms
/* Rqes :
- En cas de nb de philos paire, j'envoi les paires en premier et je
fais attendre les impaires:
if ((philo->nb_philos % 2 == 0) && (philo->pos % 2 != 0))
		usleep((philo->t_eat / 2) * 1000); 
- En cas de nb de philos impaire, j'envoi les impaires en premier et je
fais attendre les paires:
if ((philo->nb_philos % 2 != 0) && (philo->pos % 2 == 0))
		usleep((philo->t_eat / 2) * 1000);
==> *1000 pour convertir en microsec
*/
static void	handle_departure(t_philo *philo)
{
	philo->time = philo->time + (philo->nb_philos * 1000);
	while (get_time() < philo->time)
		usleep(1000);
	philo->last_meal = get_time;
	print_message(philo, "is thinking");
	if ((philo->nb_philos % 2 == 0) && (philo->pos % 2 != 0))
		usleep((philo->t_eat / 2) * 1000);
	if ((philo->nb_philos % 2 != 0) && (philo->pos % 2 == 0))
		usleep((philo->t_eat / 2) * 1000);
}

static void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->data->check_status);
	pthread_mutex_lock(philo->data->write);
	usleep((philo->t_die + 1) * 1000);
	philo_dead(philo);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
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
		
	}
}

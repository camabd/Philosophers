/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:28:02 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/25 14:57:30 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//1000 ms = approximation de temps de création d'un thread
//usleep(1000) = 1000 microsec = 1 ms
static void	handle_departure(t_philo *philo)
{
	philo->time = philo->time + (philo->nb_philos * 1000);
	while (get_time() < philo->time)
		usleep(1000);
	philo->last_meal = get_time;
	print_message(philo, "is thinking");
	
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	handle_departure(philo)
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:53:49 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/05 15:48:08 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_fully_fed(t_philo *philo)
{
	if (philo->nb_meals)
	{
		if (philo->meals_eaten == philo->nb_meals)
			return (1);
	}
	return (0);
}

/*
Remarque : 
time_to_die (in milliseconds): If a philosopher didn’t start eating
time_to_die milliseconds since the beginning of their last meal or
the beginning of the simulation, they die.
t_die = max time between the begining of two consecutive meals
donc on fait philo->last_meal = get_time(); au début du repas !!!
*/
int	eat(t_philo *philo)
{
	if (!print_message(philo, "is eating"))
		return (drop_forks(philo), 0);
	philo->last_meal = get_time();
	if (philo->nb_meals)
		philo->meals_eaten++;
	if (!my_usleep(philo, philo->t_eat))
		return (drop_forks(philo), 0);
	drop_forks(philo);
	if (philo_fully_fed(philo))
		return (0);
	return (1);
}

int	sleeping(t_philo *philo)
{
	if (!print_message(philo, "is sleeping"))
		return (0);
	if (!my_usleep(philo, philo->t_sleep))
		return (0);
	return (1);
}

int	think(t_philo *philo)
{
	if (!print_message(philo, "is thinking"))
		return (0);
	return (1);
}

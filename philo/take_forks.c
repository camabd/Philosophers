/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:09:37 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/01 16:19:44 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_forks(t_philo *philo)
{
	if (philo->pos % 2 == 0)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
	}
}

static int	even_takes_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (!print_message(philo, "has taken a fork"))
		return (pthread_mutex_unlock(philo->l_fork), 0);
	pthread_mutex_lock(philo->r_fork);
	if (!print_message(philo, "has taken a fork"))
		return (drop_forks(philo), 0);
	return (1);
}

static int	odd_takes_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	if (!print_message(philo, "has taken a fork"))
		return (pthread_mutex_unlock(philo->r_fork), 0);
	pthread_mutex_lock(philo->l_fork);
	if (!print_message(philo, "has taken a fork"))
		return (drop_forks(philo), 0);
	return (1);
}

int	take_forks(t_philo *philo)
{
	if (philo->pos % 2 == 0)
	{
		if (!even_takes_forks(philo))
			return (0);
	}
	else
	{
		if (!odd_takes_forks(philo))
			return (0);
	}
	return (1);
}

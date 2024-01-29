/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:09:37 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/29 14:52:35 by cabdli           ###   ########.fr       */
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
	if (!print_message(philo, "has taken a fork (left)"))
		return (pthread_mutex_unlock(philo->l_fork), 0);
	pthread_mutex_lock(philo->r_fork);
	if (!print_message(philo, "has taken a fork (right)"))
		return (drop_forks(philo), 0);
	return (1);
}

static int	odd_takes_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	if (!print_message(philo, "has taken a fork (right)"))
		return (pthread_mutex_unlock(philo->r_fork), 0);
	pthread_mutex_lock(philo->l_fork);
	if (!print_message(philo, "has taken a fork (left)"))
		return (drop_forks(philo), 0);
	return (1);
}

/* Pourquoi les fourchettes prises en premieres et
lachees en premieres varient en fonction de la position du philo
(philo pair ou impair) ? Permet d'être sur que lorsque le philo prend une fourchette
les 2 sont disponibles ? mais pourquoi puisque le temps d'attente semble
similaire dans les 2 cas ?*/
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

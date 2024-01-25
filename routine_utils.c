/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:38:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/25 14:12:35 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_dead(t_philo *philo)
{
	if (get_time() - philo->last_meal > philo-)
}

int	print_message(t_philo *philo, char *str)
{
	if (philo_dead)
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

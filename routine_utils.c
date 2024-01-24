/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:38:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/24 18:10:30 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	print_message(t_philo *philo, char *str)
{
	if (philo_dead)
		return (0);
	/*pthread_mutex_lock(philo->data->check_status);
	if (philo->data->status == dead)
		return (pthread_mutex_unlock(philo->data->check_status), 0);
		A mettre dans is_dead*/
	pthread_mutex_lock(philo->data->write);
	printf("%lld %d %s\n", (get_time() - philo->time), philo->pos, str);
}

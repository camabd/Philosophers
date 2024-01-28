/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:09:37 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/28 12:27:36 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	even_takes_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (!print_message(philo, "has taken a fork (left)"))
	
}

/* Pourquoi les fourchettes prises en premieres et lachees en
premieres varient en fonction de la position du philo
(philo pair ou impair) ? Permet d'être sur que lorsque le philo prend une fourchette
les 2 sont disponibles ? mais pourquoi puisque le temps d'attente semble
similaire dans les 2 cas ?*/
int	take_forks(t_philo *philo)
{
	if (philo->pos % 2 == 0)
		if (!even_takes_forks(philo))
			return (0);
	
}

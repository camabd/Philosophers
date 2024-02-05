/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sync.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:40:17 by cabdli            #+#    #+#             */
/*   Updated: 2024/02/05 15:49:49 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_sync_2(int nb, int i, t_philo **philos)
{
	if (nb % 2 != 0)
	{
		if ((*philos)[i].t_eat * 3 <= (*philos)[i].t_die \
			&& (*philos)[i].t_sleep < (*philos)[i].t_eat)
			(*philos)[i].sync += (*philos)[i].t_eat - \
			(*philos)[i].t_sleep;
		else if ((*philos)[i].t_eat * 3 > (*philos)[i].t_die \
			&& ((*philos)[i].t_sleep + (*philos)[i].t_eat) \
			< (*philos)[i].t_die)
			(*philos)[i].sync += (*philos)[i].t_die - \
			((*philos)[i].t_eat + (*philos)[i].t_sleep);
	}
	else
	{
		if ((*philos)[i].t_eat * 2 > (*philos)[i].t_die \
			&& ((*philos)[i].t_sleep + (*philos)[i].t_eat) \
			< (*philos)[i].t_die)
			(*philos)[i].sync += (*philos)[i].t_die - \
			((*philos)[i].t_eat + (*philos)[i].t_sleep);
	}
}

void	set_sync(int nb, int i, t_philo **philos)
{
	if (nb == 3)
	{
		if (i % 2 == 0)
			(*philos)[i].sync = 500;
		else
			(*philos)[i].sync = 1000;
	}
	else if (nb % 2 != 0 && i % 2 == 0)
		(*philos)[i].sync = 1000;
	else if (nb % 2 == 0)
		(*philos)[i].sync = 500;
	else
		(*philos)[i].sync = 0;
	set_sync_2(nb, i, philos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:57:33 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/09 21:18:45 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

//multiplier t_die/eat/sleep * 1000 ? Pk ?
void	collect_data(char **str, t_data *data)
{
	data->t_die = ft_atoi(str[2]);
	data->t_eat = ft_atoi(str[3]);
	data->t_sleep = ft_atoi(str[4]);
	if (str[5])
		data->nb_meals = ft_atoi(str[5]);
}

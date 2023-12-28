/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:47:34 by cabdli            #+#    #+#             */
/*   Updated: 2023/12/28 16:20:22 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	char	**str;
	t_philo	data;

	str = NULL;
	if (ac != 5 && ac != 6)
		return (printf("Error, please enter : ./philo nb_philos t_die t_eat t_sleep [nb_meals]"), 0);
	str = &av[1];
	if (!check_args(str, &data))
		return (0);
	
}

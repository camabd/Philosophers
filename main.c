/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:47:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/08 14:17:14 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	char	**str;
	t_data	data;
	t_philo	philo;

	str = NULL;
	if (ac != 5 && ac != 6)
		return (printf("Error, wrong number of arguments !\n"), 0);
	str = &av[1];
	if (!check_args(str, &data))
		return (0);
	//init threads and mutexes
	//printf("success !");
	return (1);
}

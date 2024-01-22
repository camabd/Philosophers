/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:47:34 by cabdli            #+#    #+#             */
/*   Updated: 2024/01/22 13:22:30 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	char			**str;
	t_data			data;
	t_philo			*philo;
	pthread_mutex_t	*forks;

	str = NULL;
	forks = NULL;
	philo = NULL;
	if (ac != 5 && ac != 6)
		return (printf("Error, wrong number of arguments !\n"), 0);
	str = &av[1];
	if (!check_args(str, &data))
		return (0);
	if (!collect_data(str, &data))
		return (0);
	if (!init_var(str, &forks, &philo, &data))
		return (free_destroy_all(&data, forks, philo), 0);
	if (!init_join_threads(philo, &data))
		return (free_destroy_all(&data, forks, philo), 0);
	free_destroy_all(&data, forks, philo);
	return (1);
}

// Mettre write pour tous les printf de init_threads
// pour éviter les data race ?
// !!!!! AJOUTER ROUTINE A FONCTION INIT THREADS !!!!!!
// si fonction join ne fonctionne pas, pk continuer quand meme le pgme ?

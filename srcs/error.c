/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:46:29 by nate              #+#    #+#             */
/*   Updated: 2024/08/07 07:55:23 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//	Unlock then free the mutexs of the forks, using error codes, and trylock
void	ft_destroy_mutex(t_info *info)
{
	int	i;

	i = -1;	
	while (++i < info->nb_philo)
		pthread_join(info->philo_tab[i].thread, NULL);
	i = -1;
	while (++i < info->nb_philo)
	{
		if (info->philo_tab[i].r_fork.init)
			pthread_mutex_destroy(info->philo_tab[i].r_fork.mutex);
		free(info->philo_tab[i].r_fork.mutex);
	}
}

//	Clean all the simulation, aka :
//		- Join all the threads
//		- Destroy all the mutexs
//		- Free the heap
void	stop_simu(t_info *info)
{
	ft_destroy_mutex(info);
}

//	Display the error message, stop the simulation and clear the program infos
void	ft_error(int error_code, t_info *info)
{
	if (info->printf.init)
		pthread_mutex_lock(info->printf.mutex);
	if (error_code == 1)
		printf("Arguments should be : <philo number> <time to die> <time to \
			eat> <time to sleep> optional : <number of meal>\n");
	else if (error_code == 2)
		printf("GetTimeOfDay error\n");
	else if (error_code == 3)
		printf("Malloc error\n");
	else if (error_code == 4)
		printf("%ld %d is dead\n", ft_time(info), whosdead(info));
	else if (error_code == 5)
		printf("All the philosophers have eat all their meals\n");
	stop_simu(info);
	if (info->printf.init)
	{
		pthread_mutex_unlock(info->printf.mutex);
		pthread_mutex_destroy(info->printf.mutex);
		free(info->printf.mutex);
	}
	if (info->simu_start.init)
	{
		pthread_mutex_destroy(info->simu_start.mutex);
		free(info->simu_start.mutex);
	}
	exit(1);
}

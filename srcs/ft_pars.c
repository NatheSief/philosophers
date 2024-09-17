/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:23:13 by nate              #+#    #+#             */
/*   Updated: 2024/09/16 16:43:47 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_pars(t_info *info)
{
	if (info->t_die == -1)
		return (ft_error(1, info));
	if (info->t_eat == -1)
		return (ft_error(1, info));
	if (info->t_sleep == -1)
		return (ft_error(1, info));
	if (info->limit == -1)
		return (ft_error(1, info));
	if (info->nb_philo == -1)
		return (ft_error(1, info));
	return (0);
}
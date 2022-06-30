/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:12:49 by jeounpar          #+#    #+#             */
/*   Updated: 2022/06/30 23:14:01 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	ft_eat_check(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (info->num_must_eat > 0 && i < info->num_philo
		&& philo[i].eat_cnt >= info->num_must_eat)
		i++;
	if (i == info->num_philo)
		info->eat_check = 1;
}

void	ft_death_check(t_info *info, t_philo *philo)
{
	int	i;

	while (!(info->eat_check))
	{
		i = 0;
		while ((i < info->num_philo) && (!(info->die_check)))
		{
			if ((get_time() - philo[i].time) > info->time_to_die)
			{
				p_printf(info, i, "died");
				info->die_check = 1;
			}
			usleep(10);
			i++;
		}
		if (info->die_check)
			break ;
		ft_eat_check(info, info->philos);
	}
}

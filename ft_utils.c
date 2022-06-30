/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:09:59 by jeounpar          #+#    #+#             */
/*   Updated: 2022/06/30 14:20:08 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"
#include <time.h>
#include <stdio.h>

static int	my_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static t_ull	get_result(char *str, int i, t_ull result, int neg)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = str[i] - '0' + result * 10;
		i++;
	}
	return (result * neg);
}

t_ull	ft_atoull(char *str)
{
	int		neg;
	int		cnt;
	int		i;
	t_ull	result;

	neg = 1;
	cnt = 0;
	result = 0;
	i = 0;
	while (my_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		cnt++;
		if (cnt > 1)
			return (0);
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	return (get_result(str, i, result, neg));
}

void	p_printf(t_info *info, int p_id, char *str)
{
	pthread_mutex_lock(&(info->buffer_mutex));
	if (!(info->die_check))
	{
		printf("%lldms\t%d %s\n", get_time() - info->start_time,
			p_id + 1, str);
	}
	pthread_mutex_unlock(&(info->buffer_mutex));
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:09:52 by jeounpar          #+#    #+#             */
/*   Updated: 2022/06/30 14:16:56 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_info	info;

	if (check_arguments(argc, argv) == FALSE
		|| init_info(argc, argv, &info) == FALSE)
		return (ft_print_error("Check Arguments"));
	if (ft_philo_start(&info, (&info)->philos) == FALSE)
		return (ft_print_error("Thread Create Fail\n"));
	return (0);
}

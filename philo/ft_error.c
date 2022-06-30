/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeounpar <jeounpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:09:42 by jeounpar          #+#    #+#             */
/*   Updated: 2022/06/30 23:45:17 by jeounpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

static int	print_how_to_use(void)
{
	printf("./philo number_of_philosophers time_to_die time_to ");
	printf("eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (1);
}

static int	check_minus(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	ft_print_error(char *str)
{
	print_how_to_use();
	printf("%s\n", str);
	return (FALSE);
}

int	check_arguments(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	if (check_minus(argc, argv) == FALSE)
		return (FALSE);
	return (TRUE);
}

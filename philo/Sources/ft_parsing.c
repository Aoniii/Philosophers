/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:18:48 by snourry           #+#    #+#             */
/*   Updated: 2022/12/07 15:55:43 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_struct.h"
#include "ft_utils.h"
#include <stdio.h>

static char	**ft_reformed(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		if (argv[i][j] == '+' && ft_strlen(argv[i]) > 1)
			j++;
		while (argv[i][j] == '0')
			j++;
		if (j != '0')
			argv[i] = &argv[i][j];
	}
	return (argv);
}

static bool	ft_check_argv(int argc, char **argv)
{
	int	i;
	int	j;

	argv = ft_reformed(argc, argv);
	i = 0;
	while (++i < argc)
		if (ft_strlen(argv[i]) > 9)
			return (false);
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (false);
	}
	return (true);
}

static bool	ft_check_global(int argc, char **argv)
{
	if (!ft_check_argv(argc, argv))
		printf("[\e[31mERROR\e[39m] The argument \
isn't correct !\n");
	else
		printf("[\e[31mERROR\e[39m] Usage: ./philo \
<number_of_philosophers> <time_to_die> <time_to_eat> \
<time_to_sleep> [number_of_times_each_philosopher_must_eat] !\n");
	return (false);
}

bool	ft_parsing(int argc, char **argv, t_parsing *parsing)
{
	if (argc < 5 || argc > 6 || !ft_check_argv(argc, argv))
		if (!ft_check_global(argc, argv))
			return (false);
	parsing->have_eat_limit = false;
	parsing->ph_n = ft_atoul(argv[1]);
	if (parsing->ph_n < 1)
	{
		printf("[\e[31mERROR\e[39m] You need at least 1 Philosopher !\n");
		return (false);
	}
	parsing->die_t = ft_atoul(argv[2]);
	parsing->eat_t = ft_atoul(argv[3]);
	parsing->sleep_t = ft_atoul(argv[4]);
	if (argc == 6)
	{
		parsing->have_eat_limit = true;
		parsing->eat_n = ft_atoul(argv[5]);
	}
	if (parsing->die_t == 0 || parsing->eat_t == 0 || parsing->sleep_t == 0 \
	|| (argc == 6 && parsing->eat_n == 0))
	{
		printf("[\e[31mERROR\e[39m] They values can't equals 0 !\n");
		return (false);
	}
	return (true);
}

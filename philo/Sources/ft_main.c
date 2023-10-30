/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:06:42 by snourry           #+#    #+#             */
/*   Updated: 2022/09/18 18:51:53 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

int	main(int argc, char **argv)
{
	t_program	*program;

	program = ft_init_program();
	if (!ft_parsing(argc, argv, &program->parsing))
	{
		free(program);
		program = NULL;
		return (0);
	}
	program->philo = ft_create_philo(program);
	ft_start(program);
	ft_destroy_mutex(program);
	ft_free(program, true);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:14:56 by snourry           #+#    #+#             */
/*   Updated: 2022/09/18 03:26:02 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H

# include "ft_struct.h"
# include "ft_utils.h"
# include <stdlib.h>
# include <unistd.h>

t_program	*ft_init_program(void);
t_philo		*ft_create_philo(t_program *program);
bool		ft_parsing(int argc, char **argv, t_parsing *parsing);
void		ft_free(t_program *program, bool thread);
void		ft_destroy_mutex(t_program *program);
void		ft_start(t_program *program);
void		ft_philo_print(t_philo *philo, t_states states);
bool		ft_is_finish(t_philo *philo);
void		ft_take_fork(t_philo *philo);
void		ft_eating(t_philo *philo);
void		ft_sleeping(t_philo *philo);
void		ft_check(t_program *program);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 02:14:44 by snourry           #+#    #+#             */
/*   Updated: 2022/09/18 06:16:52 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

int		ft_isdigit(int c);
size_t	ft_atoul(char *s);
size_t	ft_get_time(void);
int		ft_strlen(char *s);

#endif

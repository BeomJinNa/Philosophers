/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:04:16 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 22:19:47 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PHILO_H
# define S_PHILO_H

# include "s_fork.h"

typedef struct s_philo
{
	int		index;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		goal;
	int		count_of_eatting;
	t_fork	*left;
	t_fork	*right;
}			t_philo;
#endif

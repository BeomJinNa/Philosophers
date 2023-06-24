/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:29:48 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 22:02:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STAT_H
# define S_STAT_H

# include <pthread.h>
# include "e_philo_status.h"

typedef struct s_stat	t_stat;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

struct s_stat
{
	int				total_num;
	int				terminated_num;
	int				status;
	pthread_mutex_t	mutex_termination;
	pthread_mutex_t	mutex_status;
	t_philo			*philo;
	t_fork			*fork;
};

struct s_philo
{
	pthread_t	tid;
	int			index;
	int			status;
	int			last_meal_time;
	int			last_sleep_time;
	int			goal;
	int			count_of_eatting;
	int			time_to_start;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	t_stat		*stat;
	t_fork		*left;
	t_fork		*right;
};

struct s_fork
{
	int				index;
	int				owner;
	pthread_mutex_t	mutex;
};
#endif

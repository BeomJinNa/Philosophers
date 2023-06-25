/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:29:48 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 20:00:37 by bena             ###   ########.fr       */
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
	int				status;
	int				terminated_num;
	int				finished_num;
	int				delay;
	pthread_mutex_t	mutex_status;
	pthread_mutex_t	mutex_termination;
	pthread_mutex_t	mutex_finished;
	pthread_mutex_t	mutex_print;
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
	int			count_of_eating;
	int			goal;
	int			is_this_already_over;
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

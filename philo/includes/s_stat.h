/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:29:48 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 20:51:27 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STAT_H
# define S_STAT_H

# include <pthread.h>

typedef struct s_stat	t_stat;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

struct s_stat
{
	int		total_num;
	int		terminate_threads;
	t_philo	*philo;
	t_fork	*fork;
};

struct s_philo
{
	pthread_t	tid;
	t_stat		*stat;
	int			time_to_start;
	int			index;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			goal;
	int			count_of_eatting;
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

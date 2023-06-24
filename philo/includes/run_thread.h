/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_thread.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:54:28 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 22:27:54 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_THREAD_H
# define RUN_THREAD_H

# include <unistd.h>
# include "s_stat.h"

int			get_elapsed_time(int init);
void		say_terminated(t_stat *stat);
int			get_simulation_status(t_stat *stat);
int			die(t_philo *info);
void		take_right_fork(t_philo *info);
void		take_left_fork(t_philo *info);
void		fall_a_sleep(t_philo *info);
void		wake_up(t_philo *info);
static int	thread_actions(t_philo *info);
#endif

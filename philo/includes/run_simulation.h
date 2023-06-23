/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:36:31 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 23:36:54 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_SIMULATION_H
# define RUN_SIMULATION_H

# include "s_stat.h"

int	get_elapsed_time(int init);
int	init_threads(t_stat *stat);
int	run_loop(t_stat *stat);
int	release_threads(int index, t_stat *stat, int rt_errno);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:36:43 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 18:46:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "s_stat.h"

int	get_finished_threads(t_stat *stat);
int	set_simulation_status(t_stat *stat, int value);
int	get_simulation_status(t_stat *stat);

int	run_loop(t_stat *stat)
{
	while (1)
	{
		if (get_finished_threads(stat) >= stat->total_num)
			set_simulation_status(stat, 1);
		if (get_simulation_status(stat))
			break ;
		usleep(100);
	}
	if (get_simulation_status(stat) < 0)
		return (get_simulation_status(stat));
	return (0);
}

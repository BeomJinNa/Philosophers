/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:58:09 by bena              #+#    #+#             */
/*   Updated: 2023/06/25 19:18:37 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "s_stat.h"

int		get_elapsed_time(int init);
int		get_simulation_status(t_stat *stat);
void	set_simulation_status(t_stat *stat, int value);

int	die(t_philo *info)
{
	const int	time = get_elapsed_time(0);

	if (get_simulation_status(info->stat))
		return (1);
	set_simulation_status(info->stat, 1);
	printf("\033[1m%d \033[35m%d \033[31mdied\033[0m\n", time, info->index);
	return (1);
}

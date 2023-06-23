/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:36:43 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 23:31:32 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_loop.h"

int	run_loop(t_stat *stat)
{
	while (1)
	{
		usleep(100);
		if (stat->terminate_threads)
			break ;
	}
	if (stat->terminate_threads < 0)
		return (stat->terminate_threads);
	return (0);
}

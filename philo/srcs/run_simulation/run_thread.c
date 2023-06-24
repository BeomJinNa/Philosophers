/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:42:16 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 19:56:47 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run_thread.h"

//중간에 프로세스 종료 명령을 받았을 경우, 하던 작업을 중단하도록 설계
//중단하거나 동작이 끝난 경우, 메인 스레드에 스레드가 종료되었음을 송신
void	*run_thread(void *arg)
{
	t_philo	*info = (t_philo *)arg;

	while (1)
	{
		thread_actions(info);
		(void)info;
		usleep(1000);
	}
	return (NULL);
}
/*
static void	thread_actions(t_philo *info)
{
	int	time;

	time = get_elapsed_time(0);
	if (time < info->time_to_start)
		return ;
	take_the_fork(info->right
}
*/

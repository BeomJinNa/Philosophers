/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:40:21 by bena              #+#    #+#             */
/*   Updated: 2023/06/23 21:24:55 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_THREADS_H
# define INIT_THREADS_H

# include "s_stat.h"
# include "e_private_errors.h"

void	*run_thread(void *info);
int		get_elapsed_time(int init);
int		release_threads(int index, t_stat *stat);
#endif

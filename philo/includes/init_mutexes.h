/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:40:21 by bena              #+#    #+#             */
/*   Updated: 2023/06/24 18:50:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MUTEXES_H
# define INIT_MUTEXES_H

# include "s_stat.h"
# include "e_private_errors.h"

int	destroy_mutexes(int index, t_stat *stat, int rt_errno);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:06:33 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 17:37:25 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <unistd.h>
# include "s_args.h"
# include "get_arguments.h"

static int	wrong_arg_numbers(void);
static int	argument_error(int ga_errno);
static void	set_arguments(t_args *args, int *array);
#endif

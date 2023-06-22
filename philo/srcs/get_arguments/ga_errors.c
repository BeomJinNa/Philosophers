/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ga_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:58:37 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 17:01:52 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ga_strerr(int code)
{
	if (code == -1)
		return ("Invalid array buffer");
	else if (code == -2)
		return ("Some arguments are not numbers");
	else if (code == -3)
		return ("Malloc failed");
	else if (code == -4)
		return ("The number of arguments is bigger than buffer array size");
	else if (code == -5)
		return ("Some arguments are out of range of int");
	return ((void *)0);
}

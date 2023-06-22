/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:10:42 by bena              #+#    #+#             */
/*   Updated: 2023/06/22 17:01:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ga_is_this_wrong_character(int c)
{
	if (c == 32 || (9 <= c && c <= 13) || ('0' <= c && c <= '9')
		|| c == '+' || c == '-')
		return (0);
	return (1);
}

int	ga_is_this_space(int c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

int	ga_is_this_sign(int c)
{
	return (c == '+' || c == '-');
}

int	ga_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (c);
	return (0);
}

int	ga_strlen(const char *s)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

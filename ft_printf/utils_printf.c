/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:47:41 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/05/01 19:26:21 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recursive_putunbr(unsigned int n, int fd)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 10)
	{
		count = recursive_putunbr(n / 10, fd);
		if (count == -1)
			return (-1);
	}
	digit = (n % 10) + '0';
	if (write(fd, &digit, 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putunbr_write_check_fd(unsigned int n, int fd)
{
	if (n == 0)
	{
		if (write(fd, "0", 1) == -1)
			return (-1);
		return (1);
	}
	else
	{
		return (recursive_putunbr(n, fd));
	}
}

int	ft_putstr_write_check_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return (-1);
	len = ft_strlen(s);
	if (write(fd, s, len) == -1)
		return (-1);
	return (0);
}

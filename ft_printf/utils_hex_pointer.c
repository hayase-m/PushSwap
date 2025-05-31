/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:25:32 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/05/10 22:51:16 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_zero_fd(int fd)
{
	if (write(fd, "0", 1) == -1)
		return (-1);
	return (1);
}

int	ft_puthex_ptr_fd(uintptr_t num, int fd)
{
	char	*hex;
	char	buf[sizeof(uintptr_t) * 2];
	int		len;
	int		i;
	size_t	buf_size;

	buf_size = sizeof(uintptr_t) * 2;
	len = 0;
	i = buf_size - 1;
	if (num == 0)
		return (put_zero_fd(fd));
	hex = "0123456789abcdef";
	while (num != 0)
	{
		buf[i--] = hex[num % 16];
		num /= 16;
		len++;
	}
	if (write(fd, buf + (buf_size - len), len) == -1)
		return (-1);
	return (len);
}

int	ft_puthex_uint_fd(unsigned int num, int fd, int is_upper)
{
	char	*hex;
	char	buf[sizeof(unsigned int) * 2];
	int		len;
	int		i;
	size_t	buf_size;

	buf_size = sizeof(unsigned int) * 2;
	len = 0;
	i = buf_size - 1;
	if (num == 0)
		return (put_zero_fd(fd));
	if (is_upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	while (num != 0)
	{
		buf[i--] = hex[num % 16];
		num /= 16;
		len++;
	}
	if (write(fd, buf + (buf_size - len), len) == -1)
		return (-1);
	return (len);
}

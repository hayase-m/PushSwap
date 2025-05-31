/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaruyam <hmaruyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 02:27:17 by hmaruyam          #+#    #+#             */
/*   Updated: 2025/05/11 11:27:19 by hmaruyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char(va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	handle_string(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	if (ft_putstr_write_check_fd(str, 1) == -1)
		return (-1);
	return (ft_strlen(str));
}

int	handle_percent(va_list *ap)
{
	(void)ap;
	if (write(1, "%", 1) == -1)
		return (-1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <smakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:48:11 by smakni            #+#    #+#             */
/*   Updated: 2018/12/05 09:57:46 by smakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*case_4(wchar_t c, char *str)
{
	str[0] = (c >> 18) + 0xF0;
	str[1] = ((c >> 12) & 0x3F) + 0x80;
	str[2] = ((c >> 6) & 0x3F) + 0x80;
	str[3] = (c & 0x3F) + 0x80;
	str[4] = '\0';
	return (str);
}

char		*ft_putchar_printf(wchar_t c, char *str, int check)
{
	if (check == 1)
	{
		str[0] = c;
		str[1] = '\0';
	}
	else if (check == 2)
	{
		str[0] = (c >> 6) + 0xC0;
		str[1] = (c & 0x3F) + 0x80;
		str[2] = '\0';
	}
	else if (check == 3)
	{
		str[0] = (c >> 12) + 0xE0;
		str[1] = ((c >> 6) & 0x3F) + 0x80;
		str[2] = (c & 0x3F) + 0x80;
		str[3] = '\0';
	}
	else if (check == 4)
		str = case_4(c, str);
	return (str);
}

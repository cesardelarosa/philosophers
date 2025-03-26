/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:00:35 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/26 12:06:15 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	print_error(char *str)
{
	int	len1;
	int	len2;

	len1 = write(2, str, ft_strlen(str));
	if (len1 == -1)
		return (-1);
	len2 = write(2, "\n", 1);
	if (len2 == -1)
		return (len1);
	return (len1 + len2);
}

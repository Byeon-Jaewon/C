/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:34:05 by jbyeon            #+#    #+#             */
/*   Updated: 2020/12/22 17:34:10 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *my_strcat(char *dest, char *src)
{
    int     i;

    i = 0;
    while (dest[i] != '\0')
        i++;
    while (*src != '\0')
    {
        dest[i] = *src;
        i++;
        src++;
    }
    dest[i] = '\0';
    return (dest);
}
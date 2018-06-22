/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_text.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 08:07:26 by ksiziva           #+#    #+#             */
/*   Updated: 2018/06/22 08:14:29 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    underline()
{
    printf("\033[4m");
}

void    closeline()
{
    printf("\033[0m");
}

void    cyan()
{
    printf("\033[1;36m");
}

void    green()
{
    printf("\033[0;32m");
}

void    reset()
{
    printf("\033[0m");
}

void    yellow()
{
    printf("\033[01;33m");
}

void	magenta()
{
	printf("\033[0;35m");
}

void	red()
{
	printf("\033[0;031m");
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrenaudi <vrenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:26:49 by vrenaudi          #+#    #+#             */
/*   Updated: 2019/01/16 11:47:59 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/get_next_line.h"

typedef struct	s_lem
{
	int			nb_ants;
	t_room		*rooms;
	t_tube		*tubes;
	int			start;
	int			end;
}				t_lem;

typedef struct	s_room
{
	int			coord_x;
	int			coord_y;
	int			nb;
	char		*name;
}				t_room;

typedef struct	s_tube
{
	int			room1;
	int			room2;
}				t_tube;

#endif

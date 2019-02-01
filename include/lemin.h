/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:05:43 by smakni            #+#    #+#             */
/*   Updated: 2019/02/01 13:12:33 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

typedef struct		s_env
{
	t_node			*nodes;
	t_ant			*ants;
	char			*start;
	char			*end;
	int				nb_ants;
}					t_env;

typedef struct		s_node
{
	char	*name;
	int		x;
	int		y;
	char	**edges;
}					t_node;

typedef struct		s_ant
{
	int				nb;
	char			*current_node;
}					t_ant;

#endif

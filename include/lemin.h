/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:05:43 by smakni            #+#    #+#             */
/*   Updated: 2019/03/06 18:21:49 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

# define NB_LINE		1
# define NB_PATH		100
# define DEV			1

# if DEV == 1
#  define ERROR_NUMBER_ANTS "error with number of ants"
#  define ERROR_TOO_MANY_STARTS "error too many starts"
#  define ERROR_TOO_MANY_ENDS "error too many ends"
#  define ERROR_WITH_START_OR_END "error either end or start missing or equal"
#  define ERROR_TOO_MANY_SPACES_FOR_NODES "error too many spaces for nodes"
#  define ERROR_IN_NAME_OF_NODE "error wrong character in node's name"
#  define ERROR_DUPLICATE_ROOM "error duplicate room"
#  define ERROR_IN_COORDINATES "error in coordinates of room"
#  define ERROR_NO_PATH "error no path found"
#  define ERROR_NO_EDGE "error no edge found"
# else
#  define ERROR_NUMBER_ANTS "ERROR"
#  define ERROR_TOO_MANY_STARTS "ERROR"
#  define ERROR_TOO_MANY_ENDS "ERROR"
#  define ERROR_WITH_START_OR_END "ERROR"
#  define ERROR_TOO_MANY_SPACES_FOR_NODES "ERROR"
#  define ERROR_IN_NAME_OF_NODE "ERROR"
#  define ERROR_DUPLICATE_ROOM "ERROR"
#  define ERROR_IN_COORDINATES "ERROR"
#  define ERROR_NO_PATH "ERROR"
#  define ERROR_NO_EDGE "ERROR"
# endif

typedef struct		s_room
{
	char			*name;
	int				check;
	int				capacity;
	int				v_in;
	int				v_out;
	int				end;
	int				index;
	int				room_content;
	int				start;
}					t_room;

typedef struct		s_node
{
	t_room			room;
	struct s_node	*next;
}					t_node;

typedef struct		s_path
{
	int				*path;
	int				check;
	int				len;
	int				ants_launched;
	int				end_found;
}					t_path;

typedef struct		s_fifo
{
	int				index;
	int				path_index;
	int				from;
}					t_fifo;

typedef struct		s_res
{
	t_path			path;
	struct s_res	*next;
}					t_res;

typedef struct		s_ants
{
	int				nb_ants;
	int				nb_path;
	int				by_turn;
	int				same_ants_nb;
}					t_ants;

typedef struct		s_combinations
{
	int				*index_array;
	int				*ants_by_index;
}					t_combinations;

typedef struct		s_env
{
	char			**data;
	char			**best_flow;
	char			**flow;
	char			**matrice;
	int				end;
	int				end_index;
	int				nb_edges;
	int				nb_fifo;
	int				nb_line;
	int				nb_nodes;
	int				nb_path;
	int				start;
	int				start_index;
	int				flow_to_find;
	long			nb_ants;
	t_combinations	combi;
	t_fifo			*fifo;
	t_node			*nodes;
	t_path			*paths;
	t_res			*results;
	t_room			*rooms;
}					t_env;

char				**increase_size(char **d, char *l, int *r, int *nb_line);
int					*dup_table(int *src, int len);
int					*expand_table(int *src, int len, int to_add);
int					algo(t_env *env);
int					analyze_graph(t_env *env);
int					analyze_node_edge(t_env *env, char *line);
int					calculate_line(t_env *env);
int					fill_matrice(t_env *env, char **tab);
int					fill_room(t_env *env, char **tab);
int					init_paths(t_env *env);
int					init_paths_second(t_env *env);
int					read_data(t_env *env);
int					while_fifo(t_env *env);
int					while_fifo_second(t_env *env, char **flow);
t_path				bfs(t_env *env);
void				add_path(t_path *tocpy, int nb_path, int ptocpy, int len);
void				bfs_second(t_env *env, char **flow);
void				create_rooms(t_node *node, t_room **rooms, int nb_nodes);
void				dispatch_ants(t_env *env);
void				edmonds_karp(t_env *env);
void				fill_combinations(t_env *env);
void				fill_initial_fifo(t_env *env);
void				fill_initial_fifo_second(t_env *env, char **flow);
void				free_memory(t_env *env);
void				init_flow(t_env *env);
void				move_ants(t_env *env);
void				print_data(char **data, int nb_line);
void				print_env(t_env *env);
void				print_flow(t_env *env);
void				print_path(t_env *env);
void				reset_paths(t_env *env);

#endif

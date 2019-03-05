/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smakni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:05:43 by smakni            #+#    #+#             */
/*   Updated: 2019/03/05 14:38:25 by vrenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

#define	INFINITE	99999	
#define NB_LINE		100
#define NB_PATH		100

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
	struct	s_node 	*next;
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
	int				v_in;
	int				v_out;
}					t_fifo;

typedef struct		s_res
{
	t_path			path;
	struct	s_res	*next;
}					t_res;

typedef struct		s_ants
{
	int				nb_ants;
	int				nb_path;
	int				by_turn;
	int				same_ants_nb;
}					t_ants;

typedef struct		s_dij
{
	int				*distance;
	int				*pred;
	int				*visited;
	int				min;
	int				nextnode;
}					t_dij;

typedef struct		s_combinations
{
	int				*index_array;
	int				*ants_by_index;
	int				nb_combi;
	int				dup;
}					t_combinations;

typedef struct		s_env
{
	char			**data;
	int				**flow;
	int				**matrice;
	int				*end_links;
	int				*start_links;
	int				c_c;
	int				end;
	int				end_found;
	int				end_index;
	int				end_nb;
	int				nb_edges;
	int				nb_f_c;
	int				nb_fifo;
	int				nb_line;
	int				nb_nodes;
	int				nb_path;
	int				nb_path_ok;
	int				start;
	int				start_index;
	int				start_nb;
	int				flow_to_find;
	long			nb_ants;
	t_combinations	*combi;
	t_combinations	*final_combi;
	t_fifo			*fifo;
	t_node			*nodes;
	t_path			*prepaths;
	t_path			*paths;
	t_res			*results;
	t_room			*rooms;
}					t_env;

char				**increment_size(char **data, char *line, int realloc);
int					*dup_table(int *src, int len);
int					*expand_table(int *src, int len, int to_add);
int					algo(t_env *env);
int					analyze_graph(t_env *env);
int					analyze_node_edge(t_env *env, char *line);
int					create_matrice(t_env *env);
int					dijkstra(t_env *env, int n);
int					fill_matrice(t_env *env, char **tab);
int					fill_room(t_env *env, char **tab);
int					init_paths(t_env *env);
int					init_paths_second(t_env *env);
int					init_paths_algo(t_env *env);
int					read_data(t_env *env);
void				save_path(t_env *env, t_dij *dij);
void				add_path(t_path *tocpy, int nb_path, int pathtocpy, int len);
t_path				bfs(t_env *env);
void				bfs_second(t_env *env);
void				add_node(t_node **nodes, t_room room);
void				add_result(t_res **results, t_path path);
void				aff_data_1(t_dij *dij, int n, int count);
void				aff_data_2(t_dij *dij, int i);
void				aff_data_3(t_dij *dij, int i, t_env *env);
void				choose_combinations(t_env *env);
void				create_path_tab(t_res *res, t_path **paths_ok, int nb_paths);
void				create_rooms(t_node *node, t_room **rooms, int nb_nodes);
void				dispatch_ants(t_env *env);
void				fill_combinations(t_env *env);
void				fill_initial_fifo(t_env *env);
void				fill_initial_fifo_second(t_env *env);
void				fill_initial_fifo_algo(t_env *env);
void				free_memory(t_env *env);
void				init_flow(t_env *env);
void				move_ants(t_env *env);
void				print_data(char **data, int nb_line);
void				print_env(t_env *env);
void				print_flow(t_env *env);
void				print_path(t_env *env);
int					edmonds_karp(t_env *env);
int					while_fifo(t_env *env);
int					while_fifo_second(t_env *env, int nb_path_needed);

#endif

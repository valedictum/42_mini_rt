/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:11:49 by atang             #+#    #+#             */
/*   Updated: 2025/04/12 08:55:09 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/inc/libft.h"
# include <unistd.h> // read, close
# include <stdio.h> // size_t, printf
# include <stdlib.h>
# include <fcntl.h> // O_RDONLY macro
# include <string.h>
# include <sys/types.h> // for ssize_t
# include <math.h>
# include <errno.h>
# include <pthread.h>
# include "../minilibx/mlx.h"

# include "structs.h"
# include "initialisation.h"
# include "ray_tracing.h"
# include "vectors.h"
# include "free.h"

// DEFINITIONS //

# define BUFFER_SIZE 1024 
# define MAX_OBJECTS 100
# define MAX_TOKEN_LENGTH 50
# define SUCCESS 0
# define FAILURE -99

# define RST    "\033[0m"      /* Reset to default color */
# define RED	"\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */
# define U      "\033[4m"      /* Underlined */

// STRUCTURES//

/* typedef struct	s_Task
{
	void			(*function)(void *);
    void			*argument;
	struct s_Task	*next;
}				t_Task;

typedef struct	s_ThreadPool
{
	pthread_mutex_t	mutex_queue;
	pthread_cond_t	cond_queue;
	pthread_cond_t	notify;
	int				num_threads;
	pthread_t 		*threads;
	t_Task 			*task_queue_head;
	t_Task 			*task_queue_tail;
	bool			shutdown;
}				t_ThreadPool; */

// PROTOTYPES //

// error.c //
int			err_return(const char *message);
int			err_exit(t_Error error);
void		warn_err_exit(const char *message, t_Error error);
int			err_free_exit(t_Error error, struct Object *current, \
				t_Scene *scene);
int			warn_err_free_exit(const char *message, t_Error error, \
				struct Object *current, t_Scene *scene);
int			is_normalized_vector(t_Vector3 *vector);

// file_check.c //
int			file_exists(char *filename);
int			file_status(const char *filename);
int			filename_error(char	*filename);

// mlx.c //
void		initialise_data(t_Scene	*mlx);
int			deal_key(int key, t_Scene *scene);
int			close_button_hook(t_Scene *scene);
void		handle_exit(t_Scene *scene);

// object_utils.c //
const char	*get_object_type_str(int type);
void		print_objects_in_scene(struct Object *objects);
int			add_object(t_Scene *scene, struct Object *new_object);
void		free_objects(t_Scene *scene);

// parse_elements.c //
int			parse_ambient_light(char **line, t_AmbientLight *ambient_light);
int			parse_camera(char **line, t_Camera *camera);
int			parse_light(char **line, t_Light *light);
int			parse_position(t_Vector3 *position, char **token);
int			parse_orientation(t_Vector3 *orientation, char **token);

// parse_main.c //
int			process_line(char *line, t_Scene *scene);
int			parse_rt_file(const char *filename, t_Scene *scene);
int			parse_line(char	*line, t_Scene *scene);

// parse_objects.c //
int			parse_sphere(char **line, t_Scene *scene);
int			parse_plane(char **line, t_Scene *scene);
int			parse_cylinder(char **line, t_Scene *scene);

// parse_utils.c //
int			parse_rgb(t_Colour4 *colour, char **line);
int			parse_vector3(char **line, t_Vector3 *vec);
int			parse_position(t_Vector3 *position, char **line);
int			parse_orientation(t_Vector3 *orientation, char **line);

// print_elements.c //
void		print_ambient_light(t_AmbientLight *ambient);
void		print_camera(const t_Camera *camera);
void		print_light(const t_Light *light);

// print_objects.c //
void		print_sphere(const struct Object *object);
void		print_plane(const struct Object *object);
void		print_cylinder(const struct Object *object);
void		print_all_objects(const t_Scene *scene);

// print_utils.c //
int			print_error_and_return(const char *message, const char *token);
void		print_scene_info(t_Scene *scene);

// utils.c //
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			get_next_token(char **line, char **token);
char		*ft_strtok(char **line, const char *delim);
float		ft_strtof(const char *str, char **endptr);
float		parse_float(char **str);
int			parse_int(char	**str);

void		init_mlx(t_Scene	*scene);

/* // threads.c //
void		init_threads(t_ThreadPool *thread_pool);
void		execute_task(t_Task *task);
void		start_thread(t_ThreadPool *thread_pool);
void		submit_task(t_ThreadPool *thread_pool, t_Task task);
int			count_cpu_threads();
*/

// miscellaneous //
void		put_pixels_to_image(t_mem *mem, t_Scene *scene);
int			resize_window_hook(int width, int height, t_Scene *scene, \
				t_mem *mem);
int			expose_hook(t_Scene *scene);

#endif

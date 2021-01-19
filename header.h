#ifndef OBJ_H
# define OBJ_H

# include <stdlib.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}              t_vector;

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;
typedef struct	s_vertices
{
	t_vector		ve[3];
	t_vector		te[3];
	t_vector		no[3];
//	t_vector		normal;
	t_vec2		uv[3];
//	t_bounds	bounds;
}				t_vertices;

typedef struct	s_obj
{
	size_t		num_geometry;
    t_vector    *geometry;
    size_t      num_coordinates;
    t_vec2      *coordinates;
    size_t      num_normals;
    t_vector    *normals;
    size_t      num_polygonals;
    t_vertices  *polygonals;
  

}				t_obj;

t_obj			*create_obj_data(void);
void	malloc_obj(t_obj *obj, size_t num_geometry, size_t num_coordinates);
void	malloc_obj2(t_obj *obj, size_t num_normals, size_t num_polygonals);
void		read_obj_data(int fd, t_obj *obj);
t_vector	parse_geo(char *line);
t_vec2	parse_coord(char *line);
t_vector	parse_normals(char *line);
static void	parse_poly(t_obj *obj, size_t i, char *line);
#endif
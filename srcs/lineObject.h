#ifndef LINE_OBJECT_H
# define LINE_OBJECT_H
# include <lib3d.h>

typedef struct			s_lineData
{
	t_vector2f			pts1;
	t_vector2f			pts2;
}						t_lineData;

t_gameObject	*newLineObject( t_vector2f pos, t_vector2f pts1, t_vector2f pts2 );

#endif

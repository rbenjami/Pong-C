#ifndef GAME_OBJECT_H
# define GAME_OBJECT_H
# include "lib3d.h"

typedef struct s_gameObject t_gameObject;
struct						s_gameObject
{
	struct s_gameObject		*next;
	int						id;
	t_vector2f				pos;
	t_vector2f				velocity;
	int 					(* renderObject)(t_gameObject *object);
	int						(* updateObject)(t_gameObject *object);
	int						(* inputObject)(t_gameObject *object, int key);
	void					*data;
};

t_gameObject	*newGameObject( t_vector2f pos );
int				superUpdate( t_gameObject *object );

#endif

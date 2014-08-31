# include <libft.h>
# include "gameObject.h"

t_gameObject	*newGameObject( t_vector2f pos )
{
	static int		id = 0;
	t_gameObject	*gameObject;

	if ( ( gameObject = (t_gameObject *)ft_memalloc( sizeof(t_gameObject) ) ) == NULL )
		return (NULL);
	gameObject->next = NULL;
	gameObject->id = id++;
	gameObject->pos = pos;
	gameObject->velocity = newVector2f( 0, 0 );
	gameObject->renderObject = NULL;
	gameObject->updateObject = NULL;
	gameObject->inputObject = NULL;
	return (gameObject);
}

int				superUpdate( t_gameObject *object )
{
	object->pos = add2v( object->pos, object->velocity );
	return (1);
}

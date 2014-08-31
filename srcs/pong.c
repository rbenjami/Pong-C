# include <libft.h>
# include <lib3d.h>
# include "game.h"
# include "coreEngine.h"
# include "lineObject.h"

int		main(void)
{
	t_game			*game;
	t_coreEngine	*engine;

	game = newGame();
	engine = newCoreEngine( 60, game );
	createWindow( engine );
	start( engine );
	return (0);
}

int		inputLine( t_gameObject *object, int key )
{
	if ( key == 'q' )
		object->velocity = newVector2f( 0, -1 );
	else if ( key == 'a' )
		object->velocity = newVector2f( 0, 1 );
	else
		object->velocity = newVector2f( 0, 0 );
	return (0);
}

int		initGame( t_game *game )
{
	t_vector2f vector = newVector2f( 10, 0 );
	t_vector2f pts1 = newVector2f( 0, 0 );
	t_vector2f pts2 = newVector2f( 10, 10 );

	t_gameObject	*line = newLineObject( vector, pts1, pts2 );
	line->inputObject = inputLine;

	t_gameObject	*line2 = newLineObject( newVector2f(5, 0), newVector2f(-5, 0), newVector2f(5, 0) );
	line2->velocity = newVector2f( 0.5, 0.1 );

	addGameObject( game, line );
	addGameObject( game, line2 );
	return (1);
}

#ifndef GAME_H
# define GAME_H
# include "gameObject.h"

typedef struct				s_game
{
	t_gameObject			*rootObject;
}							t_game;

t_game	*newGame();
int		addGameObject( t_game *game, t_gameObject *object );
int		initGame();

#endif

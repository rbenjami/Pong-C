# include <libft.h>
# include "game.h"
# include "gameObject.h"

t_game	*newGame()
{
	t_game	*game;

	if ( ( game = (t_game *)ft_memalloc( sizeof(t_game) ) ) == NULL )
		return (NULL);
	game->rootObject = NULL;
	return (game);
}

int		addGameObject( t_game *game, t_gameObject *object )
{
	t_gameObject	*tmp;

	if ( game->rootObject == NULL )
		game->rootObject = object;
	else
	{
		tmp = game->rootObject;
		while ( tmp->next != NULL )
			tmp = tmp->next;
		tmp->next = object;
	}
	return (1);
}


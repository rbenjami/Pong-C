# include <libft.h>
# include "renderEngine.h"
# include "gameObject.h"

t_renderEngine		*newRenderEngine()
{
	t_renderEngine	*renderEngine;

	if ( ( renderEngine = (t_renderEngine *)ft_memalloc( sizeof(t_renderEngine) ) ) == NULL )
		return (NULL);
	return (renderEngine);
}

int		init( t_renderEngine *renderEngine )
{
	renderEngine->win = initscr();
	nodelay( renderEngine->win, TRUE );
	timeout(0);
	noecho();
	curs_set(FALSE);
	start_color();

	init_pair(DEFAULT_COLOR, COLOR_BLACK, COLOR_RED);
	return (1);
}

int		render( t_gameObject *rootObject )
{
	t_gameObject	*tmp;

	tmp = rootObject;
	while ( tmp != NULL )
	{
		if ( tmp->renderObject != NULL )
			tmp->renderObject( tmp );
		tmp = tmp->next;
	}
	return (1);
}

int		update( t_gameObject *rootObject )
{
	t_gameObject	*tmp;

	tmp = rootObject;
	while ( tmp != NULL )
	{
		if ( tmp->updateObject != NULL )
			tmp->updateObject( tmp );
		else
			superUpdate( tmp );
		tmp = tmp->next;
	}
	return (1);
}

int		input( t_gameObject *rootObject, int key )
{
	t_gameObject	*tmp;

	tmp = rootObject;
	while ( tmp != NULL )
	{
		if ( tmp->inputObject != NULL )
			tmp->inputObject( tmp, key );
		tmp = tmp->next;
	}
	return (1);
}

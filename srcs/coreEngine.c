# include <time.h>
# include <fcntl.h>
# include <libft.h>
# include "coreEngine.h"
# include "renderEngine.h"
# include "game.h"

t_coreEngine	*newCoreEngine( int framerate, t_game *game )
{
	t_coreEngine	*coreEngine;

	if ( ( coreEngine = (t_coreEngine *)ft_memalloc( sizeof(t_coreEngine) ) ) == NULL )
		return (NULL);

	coreEngine->game = game;
	coreEngine->framerate = framerate;
	return (coreEngine);
}

int			createWindow( t_coreEngine *engine )
{
	engine->renderEngine = newRenderEngine();
	init( engine->renderEngine );
	return (1);
}

int			start( t_coreEngine *engine )
{
	if ( !engine->isRuning )
	{
		engine->isRuning = TRUE;
		run( engine );
		return (1);
	}
	return (0);
}

int			stop( t_coreEngine *engine )
{
	if ( engine->isRuning )
	{
		endwin();
		engine->isRuning = FALSE;
		return (1);
	}
	return (0);
}

unsigned	getTime()
{
	return ( (unsigned)time(NULL) );
}

int			renderGame( t_game *game )
{
	render( game->rootObject );
	return (0);
}

int			updateGame( t_game *game )
{
	update( game->rootObject );
	return (0);
}

int			inputGame( t_game *game )
{
	char	buff[BUFF_SIZE + 1];

	int flag = fcntl( STDIN, F_GETFL, 0 );
	fcntl( STDIN, F_SETFL, flag | O_NONBLOCK );
	read( STDIN, buff, BUFF_SIZE );
	input( game->rootObject, buff[0] );
	return (0);
}

int			run( t_coreEngine *engine )
{
	t_game		*game;
	//long		frame;
	unsigned	startTime;
	unsigned	endTime;

	game = engine->game;
	initGame( game );

	while ( engine->isRuning )
	{
		startTime = getTime();

		clear();
		inputGame( game );
		updateGame( game );
		renderGame( game );
		refresh();

		endTime = getTime();
		usleep( ( SECOND / engine->framerate ) - ( endTime - startTime ) );
	}
	return (0);
}


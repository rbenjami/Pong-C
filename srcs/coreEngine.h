#ifndef CORE_ENGINE_H
# define CORE_ENGINE_H
# include "game.h"
# include "renderEngine.h"

# define SECOND 1000000

typedef struct		s_coreEngine
{
	int				isRuning;
	int				framerate;
	t_game			*game;
	t_renderEngine	*renderEngine;
}					t_coreEngine;

t_coreEngine	*newCoreEngine( int framerate, t_game *game );
int				createWindow( t_coreEngine *engine );
int				start( t_coreEngine *engine );
int				stop( t_coreEngine *engine );
int				run( t_coreEngine *engine );

#endif

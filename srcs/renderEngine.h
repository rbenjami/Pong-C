#ifndef RENDER_ENGINE_H
# define RENDER_ENGINE_H
# include <ncurses.h>
# include "gameObject.h"

# define STDIN				(1)
# define STDOUT				(2)
# define STDERR				(3)
# define BUFF_SIZE			(1024)

# define SET_COLOR(COLOR)	(attron(COLOR_PAIR(COLOR)))
# define DEFAULT_COLOR		(1)

typedef struct			s_renderEngine
{
	WINDOW				*win;
}						t_renderEngine;

t_renderEngine	*newRenderEngine();
int				init( t_renderEngine *renderEngine );
int				render( t_gameObject *rootObject );
int				update( t_gameObject *rootObject );
int				input( t_gameObject *rootObject, int key );

#endif

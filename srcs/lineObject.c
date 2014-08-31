# include <libft.h>
# include <lib3d.h>
# include "renderEngine.h"
# include "lineObject.h"
# include "gameObject.h"

int				renderLine( t_gameObject *object )
{
	t_lineData	*line;
	int			x0, y0, x1, y1, dx, dy, sx, sy, err, e2;

	line = (t_lineData *)object->data;

	x0 = line->pts1.x + object->pos.x;
	y0 = line->pts1.y + object->pos.y;
	x1 = line->pts2.x + object->pos.x;
	y1 = line->pts2.y + object->pos.y;

	dx = abs( x1 - x0 );
	dy = abs( y1 - y0 );
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;

	SET_COLOR(DEFAULT_COLOR);
	while (1)
	{
		mvprintw(y0, x0, "+");
		if ( x0 == x1 && y0 == y1 )
			break ;
		e2 = 2 * err;
		if ( e2 > -dy )
		{
			err -= dy;
			x0 += sx;
		}
		if ( e2 < dx )
		{
			err += dx;
			y0 += sy;
		}
	}
	return (0);
}

t_lineData		*newLineData( t_vector2f pts1, t_vector2f pts2 )
{
	t_lineData		*lineData;

	if ( ( lineData = (t_lineData *)ft_memalloc( sizeof(t_lineData) ) ) == NULL )
		return (NULL);
	lineData->pts1 = pts1;
	lineData->pts2 = pts2;
	return (lineData);
}

t_gameObject	*newLineObject( t_vector2f pos, t_vector2f pts1, t_vector2f pts2 )
{
	t_gameObject	*gameObject;

	gameObject = newGameObject( pos );
	gameObject->data = newLineData( pts1, pts2 );
	gameObject->renderObject = renderLine;
	return (gameObject);
}

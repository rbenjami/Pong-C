#include <libft.h>
# include "player.h"

t_player	*newPlayer( int num, int pts, int pos )
{
	t_player	*player;

	if ( ( player = (t_player *)ft_memalloc( sizeof(t_player) ) ) == NULL )
		return (NULL);
	player->num = num;
	player->pts = pts;
	player->pos = pos;
	return (player);
}


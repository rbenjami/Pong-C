/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:52:40 by rbenjami          #+#    #+#             */
/*   Updated: 2014/02/25 14:10:24 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_vector2f	add2f(t_vector2f vec1, float value)
{
	return (newVector2f(vec1.x + value, vec1.y + value));
}

t_vector2f	add2v(t_vector2f vec1, t_vector2f vec2)
{
	return (newVector2f(vec1.x + vec2.x, vec1.y + vec2.y));
}

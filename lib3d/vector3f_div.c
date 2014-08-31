/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:30:46 by rbenjami          #+#    #+#             */
/*   Updated: 2014/02/25 14:08:20 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_vector3f	div3f(t_vector3f vec1, float value)
{
	return (newVector3f(vec1.x / value, vec1.y / value, vec1.z / value));
}

t_vector3f	div3v(t_vector3f vec1, t_vector3f vec2)
{
	return (newVector3f(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z));
}

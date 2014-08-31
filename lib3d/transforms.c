/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:05:39 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/24 16:45:53 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_vector3f		transform(t_vector3f v, t_matrix4f m)
{
	float	x;
	float	y;
	float	z;

	x = m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z + m.m[0][3];
	y = m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z + m.m[1][3];
	z = m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z + m.m[2][3];
	return (newVector3f(x, y, z));
}

t_vector3f		getTransforms(t_vector3f v, t_vector3f t, t_quaternion r)
{
	t_matrix4f	m;
	t_vector3f	new_v;

	m = toRotationMatrix(r);
	m = mul4m(m, initTranslation(t));
	new_v = transform(v, m);
	return (new_v);
}

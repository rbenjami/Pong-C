/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4f_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 17:22:59 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/23 17:50:04 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

static t_matrix4f	initRotationX(float x)
{
	t_matrix4f	rx;

	rx.m[0][0] = 1;
	rx.m[0][1] = 0;
	rx.m[0][2] = 0;
	rx.m[0][3] = 0;
	rx.m[1][0] = 0;
	rx.m[1][1] = (float)cos(x);
	rx.m[1][2] = -(float)sin(x);
	rx.m[1][3] = 0;
	rx.m[2][0] = 0;
	rx.m[2][1] = (float)sin(x);
	rx.m[2][2] = (float)cos(x);
	rx.m[2][3] = 0;
	rx.m[3][0] = 0;
	rx.m[3][1] = 0;
	rx.m[3][2] = 0;
	rx.m[3][3] = 1;
	return (rx);
}
static t_matrix4f	initRotationY(float y)
{
	t_matrix4f	ry;

	ry.m[0][0] = (float)cos(y);
	ry.m[0][1] = 0;
	ry.m[0][2] = -(float)sin(y);
	ry.m[0][3] = 0;
	ry.m[1][0] = 0;
	ry.m[1][1] = 1;
	ry.m[1][2] = 0;
	ry.m[1][3] = 0;
	ry.m[2][0] = (float)sin(y);
	ry.m[2][1] = 0;
	ry.m[2][2] = (float)cos(y);
	ry.m[2][3] = 0;
	ry.m[3][0] = 0;
	ry.m[3][1] = 0;
	ry.m[3][2] = 0;
	ry.m[3][3] = 1;
	return (ry);
}

static t_matrix4f	initRotationZ(float z)
{
	t_matrix4f	rz;

	rz.m[0][0] = (float)cos(z);
	rz.m[0][1] = -(float)sin(z);
	rz.m[0][2] = 0;
	rz.m[0][3] = 0;
	rz.m[1][0] = (float)sin(z);
	rz.m[1][1] = (float)cos(z);
	rz.m[1][2] = 0;
	rz.m[1][3] = 0;
	rz.m[2][0] = 0;
	rz.m[2][1] = 0;
	rz.m[2][2] = 1;
	rz.m[2][3] = 0;
	rz.m[3][0] = 0;
	rz.m[3][1] = 0;
	rz.m[3][2] = 0;
	rz.m[3][3] = 1;
	return (rz);
}

t_matrix4f			initRotation3f(float x, float y, float z)
{
	t_matrix4f	rx;
	t_matrix4f	ry;
	t_matrix4f	rz;
	t_matrix4f	res;

	x = toRadians(x);
	y = toRadians(y);
	z = toRadians(z);

	rx = initRotationX(x);
	ry = initRotationY(y);
	rz = initRotationZ(z);
	res = mul4m(rz, mul4m(ry, rx));
	return (res);
}

t_matrix4f			initRotation3v(t_vector3f f, t_vector3f u, t_vector3f r)
{
	t_matrix4f	m;

	m.m[0][0] = r.x;
	m.m[0][1] = r.y;
	m.m[0][2] = r.z;
	m.m[0][3] = 0;
	m.m[1][0] = u.x;
	m.m[1][1] = u.y;
	m.m[1][2] = u.z;
	m.m[1][3] = 0;
	m.m[2][0] = f.x;
	m.m[2][1] = f.y;
	m.m[2][2] = f.z;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

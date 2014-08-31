/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 13:09:33 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/23 17:19:48 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_quaternion	newQuaternion4f(float x, float y, float z, float w)
{
	t_quaternion	quaternion;

	quaternion.x = x;
	quaternion.y = y;
	quaternion.z = z;
	quaternion.w = w;
	return (quaternion);
}

t_quaternion	newQuaternion4vf(t_vector3f axis, float angle)
{
	t_quaternion	quaternion;
	float			sinHalfAngle;
	float			cosHalfAngle;

	sinHalfAngle = (float)sin(toRadians(angle) / 2);
	cosHalfAngle = (float)cos(toRadians(angle) / 2);
	quaternion.x = axis.x * sinHalfAngle;
	quaternion.y = axis.y * sinHalfAngle;
	quaternion.z = axis.z * sinHalfAngle;
	quaternion.w = cosHalfAngle;
	return (quaternion);
}

float			length4(t_quaternion q)
{
	return ((float)sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w));
}

t_quaternion	normalized4(t_quaternion q)
{
	float	l;

	l = length4(q);
	return (newQuaternion4f(q.x / l, q.y / l, q.z / l, q.w / l));
}

t_quaternion	conjugate4(t_quaternion q)
{
	return (newQuaternion4f(-q.x, -q.y, -q.z, q.w));
}

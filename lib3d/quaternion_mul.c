/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_mul.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 16:47:31 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/24 18:17:07 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_quaternion	mul4q(t_quaternion q, t_quaternion r)
{
	float w_ = q.w * r.w - q.x * r.x - q.y * r.y - q.z * r.z;
	float x_ = q.x * r.w + q.w * r.x + q.y * r.z - q.z * r.y;
	float y_ = q.y * r.w + q.w * r.y + q.z * r.x - q.x * r.z;
	float z_ = q.z * r.w + q.w * r.z + q.x * r.y - q.y * r.x;

	return (newQuaternion4f(x_, y_, z_, w_));
}

t_quaternion	mul4v(t_quaternion q, t_vector3f r)
{
	float w_ = -q.x * r.x - q.y * r.y - q.z * r.z;
	float x_ =  q.w * r.x + q.y * r.z - q.z * r.y;
	float y_ =  q.w * r.y + q.z * r.x - q.x * r.z;
	float z_ =  q.w * r.z + q.x * r.y - q.y * r.x;

	return (newQuaternion4f(x_, y_, z_, w_));
}

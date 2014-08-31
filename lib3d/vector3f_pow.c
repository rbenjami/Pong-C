/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_pow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:52:58 by rbenjami          #+#    #+#             */
/*   Updated: 2014/03/22 13:33:12 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib3d.h"

t_vector3f	pow3f(t_vector3f vec1, float value)
{
	float	x_;
	float	y_;
	float	z_;

	x_ = pow(vec1.x, value);
	y_ = pow(vec1.y, value);
	z_ = pow(vec1.z, value);
	return (newVector3f(x_, y_, z_));
}

t_vector3f	rt3(t_vector3f vec1)
{
	float	x_;
	float	y_;
	float	z_;

	x_ = vec1.x * vec1.x;
	y_ = vec1.y * vec1.y;
	z_ = vec1.z * vec1.z;
	return (newVector3f(x_, y_, z_));
}

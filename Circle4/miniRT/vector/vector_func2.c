/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:56:15 by seykim            #+#    #+#             */
/*   Updated: 2023/12/16 18:16:02 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vec_mul_num(t_vector a, float num)
{
	t_vector	new_vec;

	new_vec.x = a.x * num;
	new_vec.y = a.y * num;
	new_vec.z = a.z * num;
	return (new_vec);
}

t_vector	vec_div_num(t_vector a, float num)
{	
	if (num == 0)
	{
		printf("Error\n:Devider is 0");
		exit(1);
	}
	return (vec_mul_num(a, (1 / num)));
}

float	vec_dot_product(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	vec_cross_product(t_vector a, t_vector b)
{
	t_vector	new_vec;

	new_vec.x = a.y * b.z - a.z * b.y;
	new_vec.y = a.z * b.x - a.x * b.z;
	new_vec.z = a.x * b.y - a.y * b.x;
	return (new_vec);
}

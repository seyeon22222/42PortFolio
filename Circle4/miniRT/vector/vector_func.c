/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seykim <seykim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:54:21 by seykim            #+#    #+#             */
/*   Updated: 2023/12/19 21:01:50 by seykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vec_add(t_vector a, t_vector b)
{
	t_vector	new_vec;

	new_vec.x = a.x + b.x;
	new_vec.y = a.y + b.y;
	new_vec.z = a.z + b.z;
	return (new_vec);
}

t_vector	vec_sub(t_vector a, t_vector b)
{
	t_vector	new_vec;

	new_vec.x = a.x - b.x;
	new_vec.y = a.y - b.y;
	new_vec.z = a.z - b.z;
	return (new_vec);
}

t_vector	vec_mul(t_vector a, t_vector b)
{
	t_vector	new_vec;

	new_vec.x = a.x * b.x;
	new_vec.y = a.y * b.y;
	new_vec.z = a.z * b.z;
	return (new_vec);
}

t_vector	vec_div(t_vector a, t_vector b)
{
	t_vector	new_vec;

	if (!b.x || !b.y || !b.z)
	{
		printf("Error\n: Devider is 0");
		exit(1);
	}
	new_vec.x = a.x / b.x;
	new_vec.y = a.y / b.y;
	new_vec.z = a.z / b.z;
	return (new_vec);
}

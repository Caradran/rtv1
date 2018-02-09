/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:29:07 by esuits            #+#    #+#             */
/*   Updated: 2018/02/03 21:39:42 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





double	hit_cylinder(t_ray ray, t_cyl cyl)
{
	double	a;
	double	c;
	double	b;
	double	delta;
	t_vect	oc;



	delta = b * b - (4 * a * c);
	if (delta <= 0)
		return(-1)
	return ((-b - sqrt(delta)) / (2.0 * a));
}

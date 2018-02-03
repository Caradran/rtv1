/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:29:07 by esuits            #+#    #+#             */
/*   Updated: 2018/02/03 16:35:06 by esuits           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





double	hit_cylinder(t_ray ray, t_cyl cyl)
{
	double	a;
	double	c;
	double	b;
	double	delta;
	t_vect	oc;


	a = ray->dir->x * ray->dir->x + ray->dir->z * ray->dir->z;
	b = 2 * ray->dir->x * (ray->ori->x - cylinder->base->x) +
		2 * ray->dir->z * (ray->ori->z - cylinder->base->z);
	c = (ray->ori->x - cylinder->base->x) * (ray->ori->x - cylinder->base->x) +
		(ray->ori->z - cylinder->base->z) * (ray->ori->z - cylinder->base->z) -
	cylinder->radius * cylinder->radius;
	delta = b * b - (4 * a * c);
	if (delta <= 0)
		return(-1)
	return ((-b - sqrt(delta)) / (2.0 * a));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:22:36 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/25 16:46:33 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include "libft.h"

typedef struct	s_fd_buffer
{
	char				*buff;
	int					fd;
	int					pad;
	long				j;
	struct s_fd_buffer	*next;
}				t_fd_buffer;

int				get_next_line(int fd, char **line);

#endif

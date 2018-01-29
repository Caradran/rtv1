/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esuits <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 00:33:28 by esuits            #+#    #+#             */
/*   Updated: 2018/01/28 17:51:12 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>
# include <SDL.h>
# include "vectors.h"
# include "libft.h"
# include "matrice.h"
# include "formes.h"

/*
** =============================================================================
** 		Colors
** =============================================================================
*/

# define C_PCL				"\033[38;2;179;102;255m"
# define C_PAT				"\033[38;2;22;160;133m"
# define C_PRM				"\033[38;2;93;188;210m"
# define C_PRT				"\033[38;2;38;106;150m"
# define C_SUC				"\033[38;2;141;143;38m"
# define C_SAT				"\033[38;2;39;174;96m"
# define C_ERR				"\033[38;2;231;76;60m"
# define C_INF				"\033[38;2;243;156;18m"

# define C_RED				"\033[38;2;231;76;60m"
# define C_ORA				"\033[38;2;230;126;34m"
# define C_YEL				"\033[38;2;241;196;15m"
# define C_GRE				"\033[38;2;46;204;113m"
# define C_TEA				"\033[38;2;26;188;156m"
# define C_BLU				"\033[38;2;52;152;219m"
# define C_PUR				"\033[38;2;155;89;182m"
# define C_PIN				"\033[38;2;236;64;122m"

# define W_RED				0xe74c3c
# define W_ORA				0xe67e22
# define W_YEL				0xf1c40f
# define W_GRE				0x2ecc71
# define W_TEA				0x1abc9c
# define W_BLU				0x3498db
# define W_PUR				0x9b59b6
# define W_PIN				0xec407a

# define C_WHI				"\033[38;2;236;240;241m"
# define C_LGR				"\033[38;2;189;195;199m"
# define C_MGR				"\033[38;2;149;165;166m"
# define C_DGR				"\033[38;2;127;140;141m"
# define C_BLA				"\033[38;2;44;62;80m"

# define W_WHI				0xecf0f1
# define W_LGR				0xbdc3c7
# define W_MGR				0x95a5a6
# define W_DGR				0x7f8c8d
# define W_BLA				0x2c3e50

# define C_NRM				"\033[0m"

/*
** =============================================================================
** 		Game related
** =============================================================================
*/

# define TITLE				"Raytracer v1.0"
# define NICK				"Rt v1.0"
# define WIDTH				1920
# define HEIGHT				1080
# define FOV				90
# define ROTATE_ANGLE		((float)FOV / (float)WIDTH * 16.0)
# define MOVE_DISTANCE		0.5

/*
** =============================================================================
** 		Strings
** =============================================================================
*/

# define HEADER				C_DGR "[ " C_PRM NICK C_DGR " ] "
# define HD					HEADER

# define W_FAIL_HD			HD C_MGR "[ " C_ERR "-" C_MGR " ] " C_LGR
# define W_INFO_HD			HD C_MGR "[ " C_INF "i" C_MGR " : "
# define W_WARN_HD			HD C_MGR "[ " C_INF "!" C_MGR " : "

# define W_FAIL_DISP(code)	C_DGR " [" C_ORA code C_DGR "]" C_MGR "]: "

# define W_ERROR(code, str)	W_FAIL_HD W_FAIL_DISP(code) C_LGR str C_LGR
# define W_INFO(str)		W_INFO_HD C_LGR str C_LGR
# define W_WARN(str)		W_WARN_HD C_LGR str C_LGR

# define W_OK				C_LGR " [" C_GRE "" C_LGR "]\n"

/*
** =============================================================================
** 		Functions
** =============================================================================
*/

/*TODO*/

#endif

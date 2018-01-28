/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeilles <mbeilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:22:36 by mbeilles          #+#    #+#             */
/*   Updated: 2017/11/17 03:19:28 by mbeilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include <stdlib.h>

/*
** --- Attributes ---
*/

# define BUFF_SIZE 8192

/*
** --- Text Format ---
*/

# define NRM				"\x1B[0m"
# define RED				"\x1B[31m"
# define GRN				"\x1B[32m"
# define YEL				"\x1B[33m"
# define BLU				"\x1B[34m"
# define MAG				"\x1B[35m"
# define CYN				"\x1B[36m"
# define WHT				"\x1B[97m"
# define LGR				"\x1B[37m"
# define DGR				"\x1B[90m"

/*
** --- Memblock error formats ---
*/

# define MB_ERR_HD			"Memblock error: "
# define MB_ERR_M_FAIL		MB_ERR_HD "malloc failed too many times, exiting"
# define MB_ERR_E_BIG		MB_ERR_HD "element bigger than block, exiting"

/*
** --- Attributes ---
*/

# define NORETURN __attribute__((noreturn)) void
# define PRINTF __attribute__((format(printf, 1, 2))) void
# define LFT_HEADER LGR "[" YEL "LFT" LGR "]"

/*
** --- Struct ---
*/

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_string
{
	uint64_t	capacity;
	uint64_t	len;
	char		*string;
}				t_string;

typedef struct	s_mem_block
{
	void				*ptr;
	size_t				index;
	size_t				block_size;
	struct s_mem_block	*next;
}				t_mem_block;

typedef struct	s_double_subdiv
{
	unsigned long		mant : 52;
	unsigned int		exp : 11;
	int					sign : 1;
}				t_double_subdiv;

typedef union	u_double
{
	double				d;
	t_double_subdiv		s;
}				t_double;

/*
** --- Char check ---
*/

int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_isspace(int c);
int				ft_isset(int c, char *set);


/*
** --- Memblock manipulation ---
*/

void			*create_block(size_t *size, const size_t limit);
t_mem_block		*create_mem_block(size_t size);
t_mem_block		*expand_mem_block(t_mem_block *block, size_t blocks);
void			*push_to_mem_block(t_mem_block *block, void *data, size_t size);
void			*store_to_mem_block(t_mem_block *block, void *d, size_t size);
void			*allocate_elem_on_mem_block(t_mem_block *block, uint32_t size);
void			*force_allocate_elem_on_mem_block(t_mem_block *b, uint32_t s);
void			remove_elem_of_mem_block(t_mem_block *b, void *d, uint32_t s);

/*
** --- Char alteration ---
*/

int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** --- String manipulation ---
*/

int				ft_atoi(char const *str);
char			*ft_itoa(int nbr);

char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);

char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char const *s1, char const *s2);

char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(char const *s, int c);

char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(char const *str, char const *to_find, size_t len);

char			*ft_strdup(const char *str);
char			*ft_strcdup(const char *str, int c);
char			*ft_strndup(const char *str, size_t n);
char			*ft_strnew(size_t size);

void			ft_strclr(char *s);
void			ft_strdel(char **as);

int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

double			ft_strtod(const char *str, char **endptr);
long			ft_strtol(const char *str, char **endptr, int base);

t_string		*ft_t_string_new(uint32_t capacity);
t_string		*ft_t_string_concat(t_string *string, char *str);
t_string		*ft_t_string_concat_len(t_string *string, char *str
		, uint32_t str_len);
void			ft_t_string_expand(t_string *string);

/*
** --- String comparison ---
*/

int				ft_strcmp(char const *str1, char const *str2);
int				ft_strncmp(char const *str1, char const *str2, size_t n);
size_t			ft_strlen(char const *str);

/*
** --- Math functions ---
*/

int				ft_get_pow(int n, int pow);

/*
** --- Memory manipulation ---
*/

int				ft_memcmp(const void *str1, const void *str2, size_t n);
void			ft_bzero(void *str, size_t n);
void			ft_memdel(void **ap);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *str1, const void *str2, int c, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memalloc(size_t size);
void			*ft_memdup(void const *tab, size_t size);
void			*ft_realloc(void *buff, size_t size, size_t n);

/*
** --- List manipulation ---
*/

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstinvert_iter(t_list **alst);

/*
** --- Primary writing ---
*/

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);

/*
** --- Filedescriptor writing ---
*/

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** --- File utils ---
*/

char			*ft_get_file_content(char *filename);

/*
** --- Utils ---
*/

# define ERR_GET_FILE_CONTENT_MALLOC LFT_HEADER " cannot get file\n"
# define ERR_FILE_OPEN LFT_HEADER " Failed to open file: "
# define MALLOC_FAILURE LFT_HEADER " malloc() failed, not enough ressources\n"
# define ERROR_NAME_HEADER LFT_HEADER " error\n"

int32_t			ft_error(uint32_t n, char **str, int32_t return_status);
NORETURN		ft_error_exit(uint32_t n, char **str, int32_t exit_status);

#endif

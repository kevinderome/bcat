/*
** braille.h for  in /home/derome_k/rendu/my_42sh/include
**
** Made by Kevin Derome
** Login   <derome_k@epitech.net>
**
** Started on  Thu May 12 18:20:59 2016 Kevin Derome
** Last update Sat Jun 25 21:41:44 2016 Kevin Derome
*/

#ifndef BRAILLE_H_
# define BRAILLE_H_
#include <stdio.h>

typedef struct	s_display
{
  char	***display;
  int	p[2];
}	t_display;

typedef struct	s_option
{
  int	print;
}	t_option;
/*
** definition des keys:
*/
# define LEFT_DISPLAY  536870935
# define RIGHT_DISPLAY  536870936
# define UP_DISPLAY 536870913
# define DOWN_DISPLAY  536870914
# define LINE_KEY  'n'
# define BEGIN_FILE 'c'
# define MIDLE_FILE ':'
# define END_FILE '-'

/*
** key_display_manager.c
*/
void	move_left(char ***tmp, int *p);
void	move_right(char ***tmp, int *p);
void	move_up(char ***tmp, int *p);
void	move_down(char ***tmp, int *p);
void	nav_function(void (**nav_f)());
/*
** display.c
*/
int	put_brl(char *str);
void	virtual_reading(char ***);
int	get_display_size(unsigned int *itab);
void	print(char ***txt);

/*
** get_next_line.c
*/
char	*get_next_line(int fd);

/*
** free_cat.c
*/
void	free_tab(void **);
void	free_display(char ***);
/*
** string.c
*/
int	my_strlen(char *str);
int	len_tab(char **ctab);
char	*my_strdup(char *str);
int	my_strcmp(char *s1, char *s2);

/*
** parse_display.c
*/
char	***convert_display(char **, int);
char	**extract_file(char *);

/*
** special_key.c
*/
void	get_nb_line(char ***, int *p);
void	begin_file(char ***txt, int *p);
void	midle_file(char ***txt, int *p);
void	end_file(char ***txt, int *p);
/*
** initialize.c
*/
int	init(char **av);
void	destroy(char ***);

#endif

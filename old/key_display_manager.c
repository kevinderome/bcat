/*
** display_manager.c for  in /home/derome_k/rendu/my_42sh
**
** Made by Kevin Derome
** Login   <derome_k@epitech.net>
**
** Started on  Thu May 12 16:10:33 2016 Kevin Derome
** Last update Sun Jun 12 00:42:50 2016 Kevin Derome
*/

#include <stdlib.h>
#include "braille.h"

void	move_left(char ***tmp, int *p)
{
  (void)tmp;
  if (p[1] != 0)
    --p[1];
  else if (p[1] == 0 && p[0] > 0)
    {
      --p[0];
      p[1] = 0;
    }
}

void	move_right(char ***tmp, int *p)
{
  if (tmp[p[0]][p[1] + 1] != NULL)
    ++p[1];
  else if (tmp[p[0]][p[1] + 1] == NULL && tmp[p[0] + 1] != NULL)
    {
      ++p[0];
      p[1] = 0;
    }
}

void	move_up(char ***tmp, int *p)
{
  (void)tmp;
  if (p[0] > 0)
    {
    --p[0];
    p[1] = 0;
    }
}

void	move_down(char ***tmp, int *p)
{
  if (tmp[p[0] + 1] != NULL)
    {
      ++p[0];
      p[1] = 0;
    }
}

void	nav_function(void (**nav_f)())
{
  nav_f[0] = &move_left;
  nav_f[1] = &move_right;
  nav_f[2] = &move_up;
  nav_f[3] = &move_down;
  nav_f[4] = &get_nb_line;
  nav_f[5] = &begin_file;
  nav_f[6] = &midle_file;
  nav_f[7] = &end_file;
}

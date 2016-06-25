/*
** free_bcat.c for  in /home/derome_k/rendu/my_42sh
**
** Made by Kevin Derome
** Login   <derome_k@epitech.net>
**
** Started on  Wed May 25 16:17:42 2016 Kevin Derome
** Last update Mon May 30 09:44:18 2016 Kevin Derome
*/

#include <stdlib.h>
#include "braille.h"

void	free_tab(void **vtab)
{
  int	i;

  i = 0;
  while (vtab[i])
    {
      free(vtab[i]);
      ++i;
    }
  free(vtab);
}

void	free_display(char ***display)
{
  int	i;

  i = 0;
  while (display[i])
    {
      free_tab((void **)display[i]);
    ++i;
    }
  free(display);
}

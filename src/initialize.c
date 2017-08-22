/*
** initialize.c for  in /home/derome_k/bcat/src
**
** Made by Kevin Derome
** Login   <derome_k@epitech.net>
**
** Started on  Sat Jun 25 21:33:06 2016 Kevin Derome
** Last update Sat Jun 25 21:43:44 2016 Kevin Derome
*/

#include "braille.h"
#include <brlapi.h>

int	init(char **av)
{
  (void)av;
  if (brlapi_openConnection(NULL, NULL) < 0)
    return (printf("bcat: Connection failled to brlapi\n"), -1);
  if (brlapi_enterTtyMode(BRLAPI_TTY_DEFAULT, NULL) < 0)
    return (printf("bcat: ttymode failled\n"), -2);
  return (0);
}

void	destroy(char ***text)
{
  printf("**********\nGood bye\n");
  brlapi_closeConnection();
  free_display(text);
}

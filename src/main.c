/*
** main.c for  in /home/derome_k/rendu/my_42sh
**
** Made by Kevin Derome
** Login   <derome_k@epitech.net>
**
** Started on  Wed May  4 01:20:09 2016 Kevin Derome
** Last update Sat Jun 25 21:34:47 2016 Kevin Derome
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <brlapi.h>
#include "braille.h"

int	main(int ac, char **av)
{
  (void)ac;
  unsigned int	size;
  char	***text;
  char	**lines;
  (void)size;

  setlocale(LC_ALL, "fr_FR.utf8");
    init(av);
  if (get_display_size(&size) < 0)
    return (printf("bcat: error with brlapi\n"), 0);
  if (ac == 1)
    return (printf("Usage: %s [option...] file(s)\n", *av), 0);
  if (! *(lines = extract_file(av[1])) ||
      ! (text = convert_display(lines, size)))
    return (printf("%s: error there are a problem\n", av[0]), -1);
  print(text);
  virtual_reading(text);
  destroy(text);
  return (0);
}

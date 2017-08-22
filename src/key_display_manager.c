
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

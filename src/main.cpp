#include "Bcat.hh"
#include "BDevice.hh"

#include <unistd.h>
#include <string>
#include <iostream>

int main(int ac, char **av)
{
  (void)ac;
  BDevice *device = new BDevice();
  Bcat bc(av[1]);
  int	key;
    
  bc.read();
  bc.start();
  device->enableAccessibilityMode();
  while (device->writeText(bc.getCurrentDisplay()))
    switch (key = device->readKey())
      {
      case 1: bc.prevLine(); break;
      case 2:  bc.nextLine(); break;
      case 3:  bc.prevRegion(); break;
      case 4: bc.nextRegion(); break;
      case 5: bc.showLine(); break;
      case 6: bc.begingFile(); break;
      case 7: bc.middleFile(); break;
      case 8: bc.endingFile(); break;
      case 9: delete device; return 0; break;
      default: std::cout << key << std::endl; break;
      }
  delete device;
  return 0;
}

#include "Bcat.hh"
#include "BDevice.hh"

#include <unistd.h>
#include <string>
#include <iostream>

void help()
{
  std::cout << "--help" << std::endl;
  std::cout << "bcat [option]" << std::endl;
  std::cout << "--version : show current version" << std::endl;
  std::cout << "--help : show this help" << std::endl;
  std::cout << "For read a simple file:" << std::endl << "bcat [filename]" << std::endl;
  std::cout << "Quick keys:" << std::endl;
  std::cout << "dots 14 : begin file" << std::endl;
  std::cout << "dots 25 : midle file" << std::endl;
  std::cout << "dots 36 : end of file" << std::endl;
  std::cout << "dots 1345 : show current line number" << std::endl;
}

void showVersion()
{
  std::cout << "--version:" << std::endl;
  std::cout << "V.1.0 Beta" << std::endl;
}

int main(int ac, char **av)
{
  if (ac != 2) {
    std::cout << av[0] << ": usage: " << av[0] << " <file>" << std::endl;
    return 1;
  }
  std::string	option = av[1];
  if (option == "--help"){
    help();
    return 0;
  }
  else if (option == "--version"){
    showVersion();
    return 0;
  }
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
      case 5:{
	bc.showLine();
	break;
      }
      case 6: bc.begingFile(); break;
      case 7: bc.middleFile(); break;
      case 8: bc.endingFile(); break;
      case 9: delete device; return 0; break;
      default: 	bc.displayOld();
      }
  delete device;
  return 0;
}

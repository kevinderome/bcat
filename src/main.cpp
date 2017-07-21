//
// main.cpp for  in /home/kevin/Bureau/projet/bcat
// 
// Made by kevin
// Login   <kevin@epitech.net>
// 
// Started on  Fri Jul 21 21:07:04 2017 kevin
// Last update Sat Jul 22 01:35:14 2017 kevin
//

#include "BDevice.hh"
#include <string>


int main()
{
  setlocale("fr-FR.utf8");
  std::string  txt = "Bonjour Kévin";

  BDevice *device = new BDevice();
  device->writeText(txt);
  while (42);
  return (0);
}

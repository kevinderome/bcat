//
// main.cpp for  in /home/kevin/Bureau/projet/bcat
// 
// Made by kevin
// Login   <kevin@epitech.net>
// 
// Started on  Fri Jul 21 21:07:04 2017 kevin
// Last update Sun Jul 23 16:56:25 2017 kevin
//

#include "BDevice.hh"
#include <unistd.h>
#include <string>
#include <iostream>


int main()
{
  setlocale(LC_ALL, "fr_FR.utf8");
  std::string  txt = "Je vais lancer bash:";

  BDevice *device = new BDevice();
  device->enableAccessibilityMode();
  device->writeText(txt);
  sleep(10);
  device->disableAccessibilityMode();
  system("bash");
  device->enableAccessibilityMode();
  device->writeText("Bash quit...");
  sleep(10);
  device->disableAccessibilityMode();
  std::cout << "info: " <<  device->getInfo() << std::endl;
  return (0);
}

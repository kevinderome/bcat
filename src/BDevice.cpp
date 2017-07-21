//
// BDevice.cpp for  in /home/kevin/Bureau/projet/bcat
// 
// Made by kevin
// Login   <kevin@epitech.net>
// 
// Started on  Fri Jul 21 21:02:20 2017 kevin
// Last update Sat Jul 22 01:27:35 2017 kevin
//


#include <brlapi.h>
#include <iostream>
#include "BDevice.hh"

BDevice::BDevice()
{
  name.resize(BRLAPI_MAXNAMELENGTH + 1);
  brlapi_openConnection(NULL, NULL);
  brlapi_enterTtyMode(BRLAPI_TTY_DEFAULT, NULL);
  brlapi_getDisplaySize(&x, &y);
  brlapi_getDriverName(&name[0], BRLAPI_MAXNAMELENGTH);
  std::cout << "name: " << name << std::endl;
}

bool BDevice::writeDots(const unsigned char *dots)
{
  if (brlapi_writeDots(dots) < 0)
    return (false);
  return (true);
}

bool BDevice::writeText(std::wstring texte)
{
  if (brlapi_writeWText(0, texte.c_str()) < 0)
    return (false);
  return (true);
}

bool BDevice::writeText(std::string texte)
{
  if (brlapi_writeText(0, texte.c_str()) < 0)
    return (false);
  return (true);
}

BDevice::~BDevice()
{
  brlapi_closeConnection();
}

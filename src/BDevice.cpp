//
// BDevice.cpp for  in /home/kevin/Bureau/projet/bcat
// 
// Made by kevin
// Login   <kevin@epitech.net>
// 
// Started on  Fri Jul 21 21:02:20 2017 kevin
// Last update Fri Jul 21 21:52:06 2017 kevin
//


#include <brlapi.h>
#include "BDevice.hh"

BDevice::BDevice()
{
  brlapi_openConnection(NULL, NULL);
  brlapi_enterTtyMode(BRLAPI_TTY_DEFAULT, NULL);
}

BDevice::~BDevice()
{
  brlapi_closeConnection();
}

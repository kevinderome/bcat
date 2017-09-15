#include "Bcat.hh"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <codecvt>
#include <locale>

Bcat::Bcat(const std::string& name)
{
  this->currentDisplay.resize(80);
  this->currentDisplay = L"Bcat: loading file...";
  this->x = 0;
  this->y = 0;
  this->posLine = 0;
  this->name = name;
}

Bcat::~Bcat()
{
}

bool	Bcat::read()
{
  std::wstring line;
  std::locale loc(std::locale(),	new std::codecvt_utf8<wchar_t>());
  std::wifstream rf;

  rf.imbue(loc);
  rf.open(this->name.c_str());
  if (rf)
    while (getline(rf, line))
      rawText.push_back(line);
  if (!rawText.size())
    rawText.push_back(L"");
  rf.close();
  return (true);
}

std::vector<std::wstring>	Bcat::parse(const std::wstring& str)
{
  size_t			count = 0;
  size_t			i = 0;
  std::wstring			parse;
  std::vector<std::wstring>	vec;
  if (! str.empty())
    while (str[count])
      {
	for (i = 0; i < 40 && str[i + count]; ++i)
	  parse += str[count + i];
	count += i;
	vec.push_back(parse);
	parse.clear();
      }
  else
    vec.push_back(L"");
  return (vec);
}

bool	Bcat::start()
{
  for (size_t i = 0; i < rawText.size(); ++i)
    this->regions.push_back(parse(rawText[i]));
  update();
  return (true);
}

std::vector<std::wstring>	Bcat::getRawText() const
{
  return (this->rawText);
}

void	Bcat::nextRegion()
{
  if (y < this->regions[x].size() -1)
    ++y;
  else if (y == this->regions[x].size() - 1)
    {
      if (x < this->regions.size() - 1)
	{
	  ++x;
	  y = 0;
	}
    }
  update();
}

void	Bcat::prevRegion()
{
  if (y > 0)
    --y;
  else if (y == 0 && x > 0)
    {
      --x;
      y = this->regions[x].size();
      if (y > 0)
	--y;
    }
  update();
}

void	Bcat::nextLine()
{
  size_t s = regions.size();

  if (s)
    --s;
  if (x < s)
    {
      ++x;
      y = 0;
    }
  update();
}

void	Bcat::prevLine()
{
  if (x > 0)
    {
      --x;
      y = 0;
    }
  update();
}

void	Bcat::begingFile()
{
  this->x = 0;
  this->y = 0;
  update();
}

void	Bcat::middleFile()
{
  this->x = this->regions.size() / 2;
  this->y = 0;
  update();
}

void	Bcat::endingFile()
{
  this->x = this->regions.size();
  if (this->x > 0)
    --x;
  this->y = this->regions[x].size();
  if (this->y > 0)
    --y;
  update();
}

void	Bcat::showLine()
{
  std::wstring	line;
  line = std::to_wstring(x + 1);
  line += L"/";
  line += std::to_wstring(this->regions.size());
  update(line);
}

void	Bcat::update()
{
  currentDisplay.clear();
  this->currentDisplay = regions[x][y];
}

void	Bcat::update(const std::wstring& str)
{
  currentDisplay.clear();
  this->currentDisplay = str;
}

const std::wstring	&Bcat::getCurrentDisplay() const
{
  return this->currentDisplay;
}

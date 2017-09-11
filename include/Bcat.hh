#ifndef BCAT_HH_
#define BCAT_HH_

#include <vector>
#include <string>

using brlRegion = std::vector<std::vector<std::wstring>>;

class Bcat
{
public:
  Bcat(const std::string& name);
  void update();
  void update(const std::wstring& str);
  bool read();
  std::vector<std::wstring> getRawText() const;
  bool start();
  void nextRegion();
  void prevRegion();
  void nextLine();
  void prevLine();
  void begingFile();
  void middleFile();
  void endingFile();
  void showLine();
  const std::wstring& getCurrentDisplay() const;
  ~Bcat();
private:
  brlRegion regions;
  std::vector<std::wstring> parse(const std::wstring& str);
  std::string name;
  std::vector<std::wstring> rawText;
  std::wstring	currentDisplay;
  size_t	x;
  size_t	y;
  size_t	posLine;
};

#endif

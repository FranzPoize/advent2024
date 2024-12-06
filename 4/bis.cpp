#include <bits/stdc++.h>

using namespace std;

constexpr int R = 140;
constexpr int C = 140;

int main (int argc, char *argv[]) {
  std::string m = "";

  for (;;)
  {
    char c;
    int eof = scanf("%c", &c);
    if (eof == EOF)
    {
      break;
    }
    if (c != '\n')
    {
      m.push_back(c);
    }
  }
  cout << m.size() << endl;

  auto checkXmasDiagMinus = [](std::string & s, int i, int j)
  {
    if (i >= R - 3 || j < 3)
      return 0;

    int count = 0;
    int p = i + C * j;
    if (s.at(p) == 'X'
      && s.at(p + 1 - C) == 'M'
      && s.at(p + 2 - 2 * C) == 'A'
      && s.at(p + 3 - 3 * C) == 'S') count++;
    if (s.at(p) == 'S'
      && s.at(p + 1 - C) == 'A'
      && s.at(p + 2 - 2 * C) == 'M'
      && s.at(p + 3 - 3 * C) == 'X') count++;
    return count;
  };

  auto checkXmasDiagPlus = [](std::string & s, int i, int j)
  {
    if (i >= R - 3 || j >= C - 3)
      return 0;

    int count = 0;
    int p = i + C * j;
    if (s.at(p) == 'X'
      && s.at(p + 1 + C) == 'M'
      && s.at(p + 2 + (2 * C)) == 'A'
      && s.at(p + 3 + (3 * C)) == 'S') count++;
    if (s.at(p) == 'S'
      && s.at(p + 1 + C) == 'A'
      && s.at(p + 2 + (2 * C)) == 'M'
      && s.at(p + 3 + (3 * C)) == 'X') count++;
    return count;
  };

  auto checkXmasHoriz = [](std::string & s, int i, int j)
  {
    if (i >= R - 3)
      return 0;

    int count = 0;
    int p = i + C * j;
    if (s.substr(p, 4) == "XMAS") count++; 
    if (s.substr(p, 4) == "SAMX") count++;
    return count;
  };

  auto checkXmasVert = [](std::string & s, int i, int j)
  {
    if (j >= C - 3)
      return 0;

    int count = 0;
    int p = i + C * j;
    if (s.at(p) == 'X'
      && s.at(p + C) == 'M'
      && s.at(p + 2 * C) == 'A'
      && s.at(p + 3 * C) == 'S') count++;
    if (s.at(p) == 'S'
      && s.at(p + C) == 'A'
      && s.at(p + 2 * C) == 'M'
      && s.at(p + 3 * C) == 'X') count++;
    return count;
  };

  int count = 0;
  for (int j = 0; j < R; j++)
  {
    for (int i = 0; i < C; i++)
    {
      count += checkXmasDiagMinus(m, i, j);
      count += checkXmasDiagPlus(m, i, j);
      count += checkXmasVert(m, i, j);
      count += checkXmasHoriz(m, i, j);
    }
  }
  cout << count;
  return 0;
}

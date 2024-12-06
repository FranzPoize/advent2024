#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[]) {
  std::vector<std::vector<int>> a;
  for (int i = 0; i < 1000; i++)
  {
    std::vector<int> b;
    while (true)
    {
      int input;
      scanf("%d", &input);
      b.push_back(input);
      char c;
      scanf("%c", &c);
      if (c == '\n') break;
    }
    a.push_back(b);
  }

  int count = 0;
  for (auto & v : a)
  {
    bool safe = false;
    for (int i = 0; i < v.size(); i++)
    {
      bool csafe = true;
      int dir = 0;
      // 0 1 2 3 4
      cout << i << endl;
      for (int * l = &(*v.begin()); l != &(*v.end()) - 1;)
      {
        int * np = l + 1;
        if ((l + 1) - &(*v.begin()) == i)
        {
          if (i == v.size() - 1) break;
          else
          {
            np += 1;
          }
        }

        if (l - &(*v.begin()) == i && i == 0)
        {
          l++;
          continue;
        }

        int c = *l;
        int n = *np;
        int diff = n - c;
        cout << n;
        int absdiff = abs(diff);
        if (diff != 0) dir += diff/absdiff;
        csafe &= absdiff > 0 && absdiff < 4 && dir != 0;
        if (diff != 0) dir = diff/absdiff;
        else dir = 0;
        l = np;
      }
      cout << endl;

      safe |= csafe;
    }

    if (safe) {
      count++;
    }
  }

  cout << count << endl;
  return 0;
}

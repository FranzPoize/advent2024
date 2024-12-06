#include <bits/stdc++.h>
#include <string>

using namespace std;

constexpr int N = 17999;

int main (int argc, char *argv[]) {
  std::vector<char> content(N);
  std::vector<std::pair<int, int>> a;

  std::string buffer = "";
  for (int i = 0; i < N; i++)
  {
    char c;
    scanf("%c", &c);
    content.push_back(c);
  }

  for (auto e : content) cout << e;

  bool enable = true;
  for (int i = 0; i < content.size() - 3; i++)
  {
    if (!enable)
    {
      if (
        i < content.size() - 3 &&
        content.at(i) == 'd' &&
        content.at(i + 1) == 'o' &&
        content.at(i + 2) == '(' &&
        content.at(i + 3) == ')'
      )
      {
        enable = true;
      }
    }
    else
    {
      if (
        i < content.size() - 6 &&
        content.at(i) == 'd' &&
        content.at(i + 1) == 'o' &&
        content.at(i + 2) == 'n' &&
        content.at(i + 3) == '\'' &&
        content.at(i + 4) == 't' &&
        content.at(i + 5) == '(' &&
        content.at(i + 6) == ')'
      )
      {
        enable = false;
        continue;
      }
      if (content.at(i) == 'm'
        && content.at(i + 1) == 'u'
        && content.at(i + 2) == 'l'
        && content.at(i + 3) == '(')
      {
        cout << content.at(i) << content.at(i + 1) << content.at(i + 2) << content.at(i + 3);
        std::pair<int, int> op = std::make_pair(0, 0);
        std::string buffer = "";
        bool found = false;
        for (int j = i + 4; true; j++)
        {
          if (j >= content.size()) break;

          if (content.at(j) >= '0' && content.at(j) <= '9')
          {
            buffer.push_back(content.at(j));
          }
          else if (content.at(j) == ',' && buffer.size() > 0)
          {
            op.first = std::stoi(buffer);
            cout << buffer << ",";
            buffer = "";
          }
          else if (content.at(j) == ')' && buffer.size() > 0)
          {
            cout << buffer << ")";
            op.second = std::stoi(buffer);
            found = true;
            break;
          }
          else
          {
            break;
          }
        }
        cout << endl;

        if (found) a.push_back(op);
      }

    }
  }
  int sum = 0;
  for (auto p : a)
  {
    sum += p.first * p.second;
  }
  cout << "sum: " << sum << endl;
  return 0;
}

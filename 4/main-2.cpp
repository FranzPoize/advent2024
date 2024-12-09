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
            if (i >= R - 2 || j >= C - 2)
                return 0;

            int count = 0;
            int p = i + C * j;
            if (((s.at(p) == 'M'
                && s.at(p + 1 + C) == 'A'
                && s.at(p + 2 + 2 * C) == 'S')
                || (s.at(p) == 'S'
                && s.at(p + 1 + C) == 'A'
                && s.at(p + 2 + 2 * C) == 'M'))
                && ((s.at(p + 2 * C) == 'M'
                && s.at(p + 1 + C) == 'A'
                && s.at(p + 2) == 'S')
                || (s.at(p + 2 * C) == 'S'
                && s.at(p + 1 + C) == 'A'
                && s.at(p + 2) == 'M'))) count++;
            return count;
        };

    int count = 0;
    for (int j = 0; j < R; j++)
    {
        for (int i = 0; i < C; i++)
        {
            count += checkXmasDiagMinus(m, i, j);
        }
    }
    cout << count;
    return 0;
}

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

int main (int argc, char *argv[]) {
    std::vector<int> a, b;
    for (int i = 0;i < 1000;i++)
    {
        int x, y;
        std::cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int r = 0;
    for (int i = 0; i < 1000; i++)
    {
        int c = 0;
        for (int j = 0; j < 1000; j++)
        {
            if (a.at(i) == b.at(j))
                c++;
        }
        r += a.at(i) * c;
    }

    std::cout << r;
    return 0;
}

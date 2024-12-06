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
    for (auto v : a)
    {
        bool safe = true;
        int dir = 0;
        for (int * l = &(*v.begin()); l != &(*v.end()) - 1; l++)
        {
            int n = *(l+1);
            int c = *l;
            int diff = n - c;
            int absdiff = abs(diff);
            if (diff != 0) dir += diff/absdiff;
            safe &= absdiff > 0 && absdiff < 4 && dir != 0;
            if (diff != 0) dir = diff/absdiff;
            else dir = 0;
        }

        if (safe) {
            count++;
            for (int i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    cout << count << endl;
    return 0;
}

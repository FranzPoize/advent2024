#include <bits/stdc++.h>
#include <cstdio>
#include <unistd.h>

using namespace std;

constexpr int R = 130;
constexpr int C = 130;

struct dir {
    int x;
    int y;

    dir operator +(const dir & other) {
        return {x + other.x, y + other.y};
    }
};

constexpr array<dir, 4> possible_dir = {{
     { 1,  0},
     { 0,  1},
     {-1,  0},
     { 0, -1}
}};

int main (int argc, char *argv[]) {
    int result = 0;
    array<char, R * C> map;
    int currentDir = 0;
    dir pos;

    auto charToDir = [](char a) {
        switch(a) {
            case '>':
                return 0;
                break;
            case 'v':
                return 1;
                break;
            case '<':
                return 2;
                break;
            case '^':
                return 3;
                break;
            default:
                return -1;
        }
    };

    for (int i = 0; i < R * C; i++)
    {
        char c;
        scanf("%c", &c);

        if (c != '\n')
            map.at(i) = c;
        else
            i--;
        int posDir = charToDir(c);

        if (posDir >= 0)
        {
            currentDir = posDir;
            cout << currentDir;
            pos = {
                i % C,
                i / C,
            };
        }

    }

    auto printMap = [&]() {
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << map.at(i * C + j);
            }
            cout << endl;
        }
    };

    for(;;)
    {
        if (map.at(pos.x + pos.y * C) != 'X')
        {
            result++;
            map.at(pos.x + pos.y * C) = 'X';
        }

        dir nextPos = pos + possible_dir.at(currentDir);
        if (nextPos.x < 0 || nextPos.x >=C || nextPos.y < 0 || nextPos.y >= R)
        {
            break;
        }

        if (map.at(nextPos.x + nextPos.y * C) == '#')
        {
            currentDir = (currentDir + 1 ) % 4;
        }
        else
        {
            pos = nextPos;
        }
    }

    printMap();
    cout << result;
    return 0;
}

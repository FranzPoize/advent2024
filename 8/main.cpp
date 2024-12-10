#include <bits/stdc++.h>
#include <cstdio>
#include <unistd.h>

using namespace std;

constexpr int R = 50;
constexpr int C = 50;
//constexpr int N = 130;

struct Vec2 {
    int x;
    int y;

    Vec2 operator +(const Vec2 & other) {
        return {x + other.x, y + other.y};
    }
    Vec2 operator -(const Vec2 & other) {
        return {x - other.x, y - other.y};
    }
    bool operator ==(const Vec2 & other) const & {
        return x == other.x && y == other.y;
    }
};

typedef array<char, R * C> Map;

void parse(Map & map)
{
    int currentDir = 0;
    Vec2 pos;
    for (int i = 0; i < R * C; i++)
    {
        char c;
        scanf("%c", &c);

        if (c != '\n')
        {
            map.at(i) = c;

        }
        else
            i--;
    }

    return;

}


void printMap(Map map_to_print) {
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << map_to_print.at(i * C + j);
        }
        cout << endl;
    }
};

bool tryPutInAntinode(Map & map, Vec2 pos)
{
    if (pos.x >= 0 && pos.x < C && pos.y >= 0 && pos.y < R)
    {
        map.at(pos.x + pos.y * C) = '#';
        return true;
    }
    return false;
}


int main (int argc, char *argv[]) {
    int result = 0;
    Map antennaMap;
    Map antinodeMap;
    memset(antinodeMap.data(), '.', R * C);
    parse(antennaMap);
    map<char, vector<Vec2>> mapAntennas;
    printMap(antennaMap);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            auto e = antennaMap.at(i * C+ j);
            if (e != '.')
            {
                if (!mapAntennas.contains(e))
                {
                    mapAntennas.insert_or_assign(e, vector<Vec2>{});
                }
                mapAntennas.at(e).push_back({j, i});
            }
        }
    }

    for (auto [k, as] : mapAntennas)
    {
        for (auto aa : as)
        {
            for (auto ab : as)
            {
                if (!(aa == ab))
                {
                    tryPutInAntinode(antennaMap, aa);
                    tryPutInAntinode(antennaMap, ab);
                    Vec2 dir = aa - ab;
                    Vec2 newPos = aa + dir;
                    while(tryPutInAntinode(antennaMap, newPos))
                    {
                        newPos = newPos + dir;
                    }
                    newPos = ab - dir;
                    while(tryPutInAntinode(antennaMap, newPos))
                    {
                        newPos = newPos - dir;
                    }
                }
            }
        }
    }
    for (auto e : antennaMap)
    {
        if (e == '#')
        {
            result++;
        }
    }

    cout << result;
    return 0;
}

#include <bits/stdc++.h>
#include <cstdio>
#include <ios>
#include <unistd.h>

using namespace std;

constexpr int R = 8;
constexpr int C = 8;
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
    bool operator !=(const Vec2 & other) const & {
        return !(*this == other);
    }
    Vec2 operator -() {
        return {-x, -y};
    }
};

typedef array<char, R * C> Map;

constexpr array<Vec2, 4> possible_direction = {{
    {1, 0},
    {0, -1},
    {-1, 0},
    {0, 1},
}};
#define right_dir possible_direction.at(0)
#define up_dir possible_direction.at(1)
#define left_dir possible_direction.at(2)
#define down_dir possible_direction.at(3)

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

void print_map(Map map_to_print) {
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << map_to_print.at(i * C + j);
        }
        cout << endl;
    }
};

#define posToIndex(x, y) (x) + (y) * C

#define MapIteration(x, y) for (int (y) = 0; (y) < R; (y)++) \
{ \
    for (int (x) = 0; (x) < C; (x)++)

#define EndIteration }

#define outPos(p) ((p).x < 0 || (p).x >= R || (p).y < 0 || (p).y >= C)
#define inPos(p) !((p).x < 0 || (p).x >= R || (p).y < 0 || (p).y >= C)
#define outCoord(x, y) ((x) < 0 || (x) >= R || (y) < 0 || (y) >= C)
#define inCoord(x, y) !((x) < 0 || (x) >= R || (y) < 0 || (y) >= C)

static Map globalMap;

bool can_i_step(Map & aMap, Vec2 pos, int prev_value)
{
    if (!inPos(pos))
    {
        return false;
    }
    char value = aMap.at(posToIndex(pos.x, pos.y));
    int intValue = value - '0';
    return value != 'X' && (intValue - prev_value) == 1;
}

int step(Map & aMap, Vec2 pos);
int step(Map & aMap, Vec2 pos)
{
    char * value = &aMap.at(posToIndex(pos.x, pos.y));
    char pre_value = *value;
    int intValue = *value - '0';
    *value = 'X';

    if (pre_value == '9')
    {
        return 1;
    }

    int result = 0;

    for (Vec2 newDir : possible_direction)
    {
        if (can_i_step(aMap, pos + newDir, intValue))
        {
            result += step(aMap, pos + newDir);
        }
    }

    return result;
}

int main (int argc, char *argv[]) {
    memset(&globalMap, '.', R * C);
    int result = 0;
    Map heightMap;
    parse(heightMap);
    print_map(heightMap);
    // Decision
    // Find the number of ways to reach nines from 0s
    //
    // From a {x, y}:
    // try step {x, y - 1}:
    //  - if height difference 1 and in step {x, y - 1}
    //  - else stop
    // try step {x + 1, y}:
    //  - if height difference 1 and in step {x + 1, y}
    //  - else stop
    // try step {x, y + 1}:
    //  - if height difference 1 and in step {x, y + 1}
    //  - else stop
    // try step {x - 1, y}:
    //  - if height difference 1 and in step {x - 1, y}
    //  - else stop

    vector<Vec2> zeroPos;
    MapIteration(i, j)
    {
        if (heightMap.at(posToIndex(i, j)) == '0')
        {
            zeroPos.push_back({i, j});
        }
    }
    EndIteration

    for (Vec2 pos : zeroPos)
    {

        Map map = heightMap;
        int zValue = step(map, pos);
        print_map(map);
        cout << endl;
        cout << zValue << endl;
        result += zValue;
    }
    print_map(globalMap);

    cout << result;
    return 0;
}

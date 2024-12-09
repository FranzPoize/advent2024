#include <bits/stdc++.h>
#include <cstdio>
#include <unistd.h>

using namespace std;

// constexpr int R = 10;
// constexpr int C = 10;
constexpr int R = 130;
constexpr int C = 130;

struct Vec2 {
    int x;
    int y;

    Vec2 operator +(const Vec2 & other) {
        return {x + other.x, y + other.y};
    }
    bool operator ==(const Vec2 & other) const & {
        return x == other.x && y == other.y;
    }
};

typedef array<char, R * C> Map;

constexpr array<Vec2, 4> possible_dir = {{
     { 1,  0},
     { 0,  1},
     {-1,  0},
     { 0, -1}
}};

constexpr unsigned char empty_char = 0;
constexpr unsigned char right_d = 1 << 0;
constexpr unsigned char down_d = 1 << 1;
constexpr unsigned char left_d = 1 << 2;
constexpr unsigned char up_d = 1 << 3;
constexpr unsigned char obstacle_char = 1 << 4;
constexpr unsigned char start_char = 1 << 5;

constexpr array<char, 4> trail = {{
    right_d, //'>',
    down_d, //'v',
    left_d, //'<',
    up_d, //'^'
}};

constexpr array<char, 16> bitToChar = {{
    '.', // 0
    '>', // 1
    'v', // 10
    '+', // 11
    '<', // 100
    '+', // 101
    '+', // 110
    '+', // 111
    '^', // 1000
    '+', // 1001
    '+', // 1010
    '+', // 1011
    '+', // 1100
    '+', // 1101
    '+', // 1110
    '+', // 1111
}};

char getChar_FromMap_AtPos(Map map, Vec2 pos)
{
    return 0;
}


char charToDir(char a) {
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

void printMap(Map map_to_print) {
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            unsigned char c = map_to_print.at(i * C + j);
            if (c < 16)
                cout << bitToChar[c];
            else
            {
                if (map_to_print.at(i * C +j) == obstacle_char)
                    cout << '#';
                else if (c != 0)
                    cout << map_to_print.at(i * C + j);
            }
        }
        cout << endl;
    }
};

pair<Vec2, int> parse(Map & map)
{
    int currentDir = 0;
    Vec2 pos;
    for (int i = 0; i < R * C; i++)
    {
        char c;
        scanf("%c", &c);

        if (c != '\n')
        {
            if (c == '.')
            {
                map.at(i) = empty_char;
            }
            else if (c == '#')
            {
                map.at(i) = obstacle_char;
            }

        }
        else
            i--;
        int posDir = charToDir(c);

        if (posDir >= 0)
        {
            currentDir = posDir;
            pos = {
                i % C,
                i / C,
            };
        }
    }

    return make_pair(pos, currentDir);

}

bool walkOnMap_FromPos_inDir_UntilLoop_OrOut(Map map, Vec2 pos, int  dirIndex)
{
    for (;;)
    {
        if (
            map.at(pos.x + pos.y * C) & trail.at(dirIndex)
        )
        {
            // printMap(map);
            // cout << endl;
            // sleep(3);
            return true;
        }

        map.at(pos.x + pos.y * C) |= trail.at(dirIndex);
        Vec2 nextPos = pos + possible_dir.at(dirIndex);
        if (nextPos.x < 0 || nextPos.x >=C || nextPos.y < 0 || nextPos.y >= R)
        {
            break;
        }
        if (map.at(nextPos.x + nextPos.y * C) & obstacle_char)
        {
            dirIndex = (dirIndex + 1 ) % 4;
        }
        else
        {
            pos = nextPos;
        }
    }
    return false;

}


int main (int argc, char *argv[]) {
    int result = 0;
    Map baseMap;
    Map temp;

    auto [pos, currentDir] = parse(baseMap);
    baseMap.at(pos.x + pos.y + C) = empty_char;

    Map map = baseMap;
    Vec2 startPos = pos;
    int baseDir = currentDir;

    //printMap(map);

    for(;;)
    {

        if (map.at(pos.x + pos.y * C) != 'X')
        {
            map.at(pos.x + pos.y * C) = 'X';
        }

        Vec2 nextPos = pos + possible_dir.at(currentDir);
        char candidateLoopDir = trail.at((currentDir + 1) % trail.size());

        if (nextPos.x < 0 || nextPos.x >=C || nextPos.y < 0 || nextPos.y >= R)
        {
            break;
        }

        if (map.at(nextPos.x + nextPos.y * C) == obstacle_char)
        {
            currentDir = (currentDir + 1 ) % 4;
        }
        else
        {
            pos = nextPos;
        }
        map.at(pos.x + pos.y * C) |= trail.at(currentDir);
        //printMap(map);
        // printMap(obstacle);
        //usleep(200000);
    }

    vector<Vec2> obstacles_possible;
    for(int i = 0; i < R * C; i++)
    {
        if (map.at(i) == 'X')
        {
            obstacles_possible.push_back({i % C, i / C});
        }
    }

    Map obstacles;
    for (auto e : obstacles_possible)
    {
        Map curMap = baseMap;
        curMap.at(e.x + e.y * C) = obstacle_char;
        //printMap(curMap);
        //cout << endl;
        if (walkOnMap_FromPos_inDir_UntilLoop_OrOut(curMap, startPos, baseDir))
        {
            result++;
        }
    }

    //printMap(map);
    cout << result;
    return 0;
}

#include <bits/stdc++.h>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

constexpr long long N = 20;
int main (int argc, char *argv[]) {
    unsigned long long result = 0;
    string diskmap;

    char c;
    while(scanf("%c", &c) != EOF)
    {
        diskmap.push_back(c);
    }

    bool file = true;
    int fileIndex = 0;
    vector<int> disk;
    int fileCount = 0;
    for (char e : diskmap)
    {
        int f = file ? fileIndex : -1;
        fileIndex += file ? 1 : 0;
        for (int i = 0; i < e - '0'; i++)
        {
            disk.push_back(f);
            fileCount += file ? 1 : 0;
        }
        file = !file;
    }

    auto findSpace = [&](int * b, int * e, int size) {
        int * t = b;
        int empty_block_size = 0;
        while(t <= e)
        {
            if (*t == -1)
            {
                empty_block_size++;
                if (empty_block_size >= size)
                {
                    return t;
                }
            }
            else
            {
                empty_block_size = 0;
            }
            t++;
        }
        return (int*)nullptr;
    };

    auto getBlock = [&](int * e, int * b) {
        // 0...111...22
        int * currentPtr = e;
        int * startPtr = e;
        while(*currentPtr == -1)
        {
            currentPtr--;
        }
        startPtr = currentPtr;

        while(*currentPtr == *startPtr)
        {
            currentPtr--;
        }
        return make_pair(startPtr, currentPtr);
    };

    auto replaceBlock = [&](int * place, int * start, int * end) {
        for (; start > end; start--)
        {
            *place = *start;
            *start = -1;
            place--;
        }
    };

    vector<int> resultString = disk;
    // for (auto e : resultString)
    // {
    //     cout << (char)((e != -1) ? e + '0' : '.');
    // }
    // for (auto e : resultString)
    // {
    //     cout << e << " ";
    // }
    int * b = &(*resultString.begin());
    int * e = &(*resultString.end()) - 1;
    while (e >= b)
    {
        auto [start, end] = getBlock(e, b);
        int size = start - end;
        int * blockPlace = findSpace(b, end, size);
        if (blockPlace != nullptr)
        {
            replaceBlock(blockPlace, start, end);
        }
        e = end;
    }

    // for (auto e : resultString)
    // {
    //     cout << (char)((e != -1) ? (e % 10) + '0' : ' ');
    // }
    for (auto e : resultString)
    {
        cout << e << " ";
    }
    cout << endl;
    for (int i = 0; i < resultString.size(); i++)
    {
        if (resultString.at(i) != -1)
        {
            result += i * (resultString.at(i));
        }
    }
    cout << result;
    return 0;
}

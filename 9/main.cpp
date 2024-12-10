#include <bits/stdc++.h>
#include <cstdio>
#include <unistd.h>

using namespace std;

constexpr long long N = 850;
int main (int argc, char *argv[]) {
    long long result = 0;
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
    int * b = &(*disk.begin());
    int * e = &(*disk.end()) - 1;

    vector<int> resultString;
    for (int i = 0; i < fileCount; i++)
    {
        int fileIndex;
        if (*b != -1)
        {
            fileIndex = *(b);
        }
        else
        {
            fileIndex = *(e--);
            while(*e == -1)
            {
                e--;
            }
        }
        b++;
        resultString.push_back(fileIndex);
    }

    cout << result;
    return 0;
}

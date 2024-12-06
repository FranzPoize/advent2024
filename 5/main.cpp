#include <bits/stdc++.h>
#include <map>

using namespace std;

constexpr int R = 140;
constexpr int C = 140;

int main (int argc, char *argv[]) {
    std::map<int, vector<int>> ruleMap;
    vector<pair<int, int>> rules;

    for (;;)
    {
        char d, u, c;
        int a, b;
        scanf("%c", &d);
        if (d == '\n') break;
        scanf("%c", &u);
        a = (d - '0') * 10 + (u - '0');

        scanf("%c", &c);

        scanf("%c", &d);
        scanf("%c", &u);
        b = (d - '0') * 10 + (u - '0');
        ruleMap.insert_or_assign(b, vector<int>{});

        scanf("%c", &c);

        rules.push_back(make_pair(a, b));
    }

    vector<vector<int>> updates;
    updates.push_back({});
    for (;;)
    {
        char c;
        int a;
        cin >> a;
        updates.back().push_back(a);
        if (scanf("%c", &c) == EOF) break;
        if (c == '\n')
        {
            updates.push_back({});
        }
    }

    updates.pop_back();

    for (auto [a, b] : rules)
    {
        //cout << a << " pushed in " << b << endl;
        ruleMap.at(b).push_back(a);
    }

    int result = 0;
    for (auto us : updates)
    {
        for (auto u : us)
            cout << u << ",";
        cout << endl;
        bool goodUpdate = true;
        for (auto u = us.begin(); u != us.end(); u++)
        {
            int * n = &*u;
            if (ruleMap.contains(*n))
            {
                vector<int> avoid = ruleMap.at(*n);
                for (int * next = n + 1; next < &(*us.end()); next++)
                {
                    if (std::find(avoid.begin(), avoid.end(), *next) != avoid.end())
                    {
                        // cout << *next << " in rule for " << *n << endl;
                        goodUpdate = false;
                    }
                }
            }
        }

        if (goodUpdate)
        {

            result += *(&(*us.begin()) + (int)ceil(us.size() / 2));

        }
    }

    cout << result;
    return 0;
}

#include <bits/stdc++.h>
#include <cstdio>
#include <unistd.h>

using namespace std;

constexpr long long N = 850;

typedef pair<long long, vector<long long>> op;
typedef array<op, N> operations;
long long multiply(vector<long long> el, long long target, long long amount, long long index);
long long add(vector<long long> el, long long target, long long amount, long long index);
long long concat(vector<long long> el, long long target, long long amount, long long index);

long long multiply(vector<long long> el, long long target, long long amount, long long index)
{
    if (index == el.size())
    {
        return amount == target;
    }
    else
    {
        return multiply(el, target, amount * el.at(index), index + 1)
            || add(el, target, amount * el.at(index), index + 1)
            || concat(el, target, amount * el.at(index), index + 1);
    }
}

long long add(vector<long long> el, long long target, long long amount, long long index)
{
    if (index == el.size())
    {
        return amount == target;
    }
    else
    {
        return multiply(el, target, amount + el.at(index), index + 1)
            || add(el, target, amount + el.at(index), index + 1)
            || concat(el, target, amount + el.at(index), index + 1);
    }
}

long long concat(vector<long long> el, long long target, long long amount, long long index)
{
    if (index == el.size())
    {
        return amount == target;
    }
    else
    {
        stringstream concatSs;
        concatSs << amount << el.at(index);
        long long newValue;
        concatSs >> newValue;
        return multiply(el, target, newValue, index + 1)
            || add(el, target, newValue, index + 1)
            || concat(el, target, newValue, index + 1);
    }
}

int main (int argc, char *argv[]) {
    long long result = 0;
    operations operations;

    for (long long i = 0; i < N; i++)
    {
        op o;
        long long r;
        cin >> r;
        char colon;
        //colon
        scanf("%c", &colon);
        //space
        scanf("%c", &colon);

        vector<long long> operands;
        long long operand = 0;

        while (true)
        {
            char c;
            scanf("%c", &c);

            if (c == ' ')
            {
                operands.push_back(operand);
                operand = 0;
                continue;
            }
            if (c == '\n')
            {
                operands.push_back(operand);
                break;
            }

            operand = operand * 10 + (c - '0');
        }
        operations.at(i) = make_pair(r, operands);
    }

    // 1 2 3
    // multiply:
    //      - multiply amount by ith + 1
    // add:
    //      - add ith + 1 to amount
    // if ith + 1 == length:
    //  result = amount == target
    for (auto o : operations)
    {
        if (add(o.second, o.first, 0, 0) || multiply(o.second, o.first, 1, 0) || concat(o.second, o.first, 0, 0))
        {
            result += o.first;
        }
    }
    cout << result;

    return 0;
}

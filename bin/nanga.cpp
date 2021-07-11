/**
 * @file nanga.cpp
 *
 * @version 01.01 2021513
 *
 * @brief https://training.olinfo.it/#/task/nanga/statement
 *
 * @ingroup nanga
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */
#include <bits/stdc++.h>
#define DEBUG
using namespace std;

int N, max_value, max_alt, actual, tmp, last;
vector <int> alt;

int main()
{
    freopen("input.txt", "r", stdin);
#ifndef DEBUG
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    cin >> N;
    actual = 5000;
    alt.resize(N);

    for (size_t i = 0; i < N; ++i)
    {
        cin >> tmp;
        actual += tmp;
        alt[i] = actual;
    }

    sort(alt.begin(), alt.end());

    max_value = INT_MIN;
    tmp = 0;
    last = -1;
    for (size_t i = 0; i < N; ++i)
    {
        if (alt[i] == last)
        {
            tmp++;
        }
        else
        {
            if(tmp > max_value)
            {
                max_value = tmp;
                max_alt = last;
            }
            last = alt[i];
            tmp = 1;
        }
    }

    cout << max_alt;
}

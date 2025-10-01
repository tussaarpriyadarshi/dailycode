
#include <bits/stdc++.h>
using namespace std;

int solve(int k, int r)
{
    for (int n = 1; n <= 10; n++)
    {
        int digit = k * n;
        int rem = digit % 10;
        if (rem == r || rem == 0)
        {
            return n;
        }
    }
    return 10;
}
int main()
{
    int k;

    cin >> k;
    int r;

    cin >> r;

    cout << solve(k, r) << endl;
    return 0;
}
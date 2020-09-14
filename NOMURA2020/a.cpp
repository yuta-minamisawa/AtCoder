#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h[2], m[2], k;
    cin >> h[0] >> m[0] >> h[1] >>  m[1] >> k;
    int a, b;
    a = h[0] * 60 + m[0];
    b = h[1] * 60 + m[1];
    cout << b - a - k << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define DIV 1000000000

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main()
{
    ull a;
    double b;
    cin >> a >> b;
    ull tmp = b *  100LL + 0.5;

    cout << a * tmp / 100LL << endl;
    return 0;
}
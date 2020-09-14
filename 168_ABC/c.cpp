#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double anga, angb;
    anga = M_PI / 6.0 * h + M_PI / 360.0 * m;
    angb = M_PI / 30.0 * m;
    cout << fixed << setprecision(10);
    double theta;
    theta = abs(anga-angb);
    cout << sqrt(a*a + b*b - 2.0 * a * b * cos(theta)) << endl;
    return 0;
}
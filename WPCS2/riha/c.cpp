#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main()
{
    int t;
    cin >> t;
    rep(i, t){
        int n;
        cin >> n;
        int sum=0;
        rep(j, n){
            int x;
            cin >> x;
            sum += x;
        }
        cout << sum << endl;
    }
    return 0;
}
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
        int n, k;
        cin >> n >> k;
        int sum=k * (n/k);
        int rest=n - sum + n/k;
        while(rest>=k){
            sum += k * (rest/k);
            rest = rest - k * (rest / k) + rest / k;
        }
        cout << sum + rest << endl;
    }
    return 0;
}
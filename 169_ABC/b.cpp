#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD LLONG_MAX

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

ll binary_square(ll x, ll n);

int main()
{
    int n;
    cin >> n;
    ll limit = binary_square(10, 18);
    //cout << limit << endl;
    ll ans=1;
    vector<ll> a;
    rep(i, n){
        ll x;
        cin >> x;
        if(x==0){
            cout << x << endl;
            return 0;
        }
        a.push_back(x);
    }

    rep(i, n){
        ll nowlimit = limit / ans;
        if(a[i]>nowlimit){
            ans = -1;
            break;
        }
        ll tmp = ans * a[i];
        ans = tmp;
    }
    cout << ans << endl;
    return 0;
}

ll binary_square(ll x, ll n)
{
    ll m = MOD;
    ll ans = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            ans = ans * x % m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return ans % m;
}
#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)
#define MOD LLONG_MAX

using namespace std;
using ll = unsigned long long;
using P = pair<int, int>;

ll binary_square(ll x, ll n);

int main()
{
    int n;
    vector<ll> a, ok;
    ll limit = binary_square(10, 14);
    cin >> n;
    rep(i, n + 1)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    if(n==0){
        int ans;
        if(a[0]==1){
            ans = 1;
        }else{
            ans = -1;
        }
        cout << ans << endl;
        return 0;
    }

    if (n < 47)
    {
        ll oknum = 1ULL;
        ok.push_back(1);
        rep(i, n)
        {
            if (oknum <= a[i])
            {
                cout << -1 << endl;
                return 0;
            }
            oknum -= a[i];
            oknum <<= 1;
            ok.push_back(oknum);
        }
        ok.pop_back();
    }
    else
    {
        ll oknum = 1ULL;
        ok.push_back(1);
        rep(i, n)
        {
            
            if (oknum <= a[i])
            {
                cout << -1 << endl;
                return 0;
            }
            oknum -= a[i];
            oknum <<= 1;
            ok.push_back(oknum);
        }

        ok.pop_back();
    }

    ll ans = a[n], nowp = a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        ll tmp = min(nowp + a[i], ok[i]);
        if (nowp % 2 == 0)
        {
            if (tmp < nowp / 2)
            {
                cout << -1 << endl;
                return 0;
            }
        }
        else
        {
            if (tmp < nowp / 2 + 1)
            {
                cout << -1 << endl;
                return 0;
            }
        }
        nowp = tmp;
        ans += nowp;
    }

    cout << ans << endl;
    return 0;
}

ll binary_square(ll x, ll n)
{
    ll m = MOD;
    ll ans = 1ULL;
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

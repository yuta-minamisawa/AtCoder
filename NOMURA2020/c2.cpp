#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ull = unsigned long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<ull> a;
    rep(i, n+1){
        ull x;
        cin >> x;
        a.push_back(x);
    }
    vector<ull> minim(n+1, 0ULL), maxim(n+1, 0ULL);

    minim[n] = a[n];
    maxim[n] = a[n];

    for(int i=n-1;i>=0;i--){
        maxim[i] = maxim[i+1] + a[i];
        minim[i] = (minim[i+1] + 1) / 2 + a[i];
    }

    ull ok=1ULL, ans=0;
    if(n==0){
        if(a[0]!=1){
            cout << -1 << endl;
        }else{
            cout << 1 << endl;
        }
        return 0;
    }

    rep(i, n+1){
        if(minim[i]>ok||(i!=n&&minim[i]>maxim[i+1]+a[i])){
            cout << -1 << endl;
            return 0;
        }
        ull tmp = min(ok, maxim[i]);
        ans += tmp;
        ok = tmp - a[i];
        ok<<=1;
    }

    cout << ans << endl;

    return 0;
}
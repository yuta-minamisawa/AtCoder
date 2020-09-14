#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<ll> a;
    rep(i, n){
        ll num;
        cin >> num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    ll sum=0;
    sum += a[n-1];
    for(int i=2;i<n;i+=2){
        if(i+1<n){
            sum+=a[n-1-i/2] * 2LL;
        }else{
            sum += a[n-1-i/2];
        }
    }
    cout << sum << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<ll> pq;
    rep(i, n){
        ll x;
        cin >> x;
        pq.push(x);
    }
    
    rep(i, m){
        ll top = pq.top();
        pq.pop();
        top /= 2;
        pq.push(top);
    }

    ll sum = 0;
    rep(i, n){
        sum += pq.top();
        pq.pop();
    }

    cout << sum << endl;
    return 0;
}
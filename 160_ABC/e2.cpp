#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int x, y , a, b, c;
    cin >> x >> y  >> a >> b >> c;
    vector<ll> p, q, r;
    ll num;
    rep(i, a){
        cin >> num;
        p.push_back(num);        
    }
    rep(i, b)
    {
        cin >> num;
        q.push_back(num);
    }
    rep(i, c)
    {
        cin >> num;
        r.push_back(num);
    }
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    p.resize(x);
    q.resize(y);
    priority_queue<ll> pq;
    rep(i, x){
        pq.push(p[i]);
    }
    rep(i, y){
        pq.push(q[i]);
    }
    rep(i, c){
        pq.push(r[i]);
    }
    ll ans=0;
    rep(i, x+y){
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}
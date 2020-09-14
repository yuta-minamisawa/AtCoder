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
    vector<int> q, P, Y;
    vector<vector<int>> vq(n+1, q);
    rep(i, m){
        int p, y;
        cin >> p >> y;
        P.push_back(p);
        Y.push_back(y);
        vq[p].push_back(y);
    }

    rep2(i, 1, n+1){
        sort(vq[i].begin(), vq[i].end());
    }

    rep(i, m){
        int nowp = P[i], digp=0;
        while(nowp){
            nowp /= 10;
            digp++;
        }
        auto it = lower_bound(vq[P[i]].begin(), vq[P[i]].end(), Y[i]);
        int x = it - vq[P[i]].begin() + 1, digx=0;
        while (x) {
          x /= 10;
          digx++;
        }
        rep(j, 6-digp){
            cout << 0;
        }
        cout << P[i];
        rep(j, 6-digx){
            cout << 0;
        }
        cout << it - vq[P[i]].begin() + 1<< endl;
    }
    return 0;
}
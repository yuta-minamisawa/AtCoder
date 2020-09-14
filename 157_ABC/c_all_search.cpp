#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int n, m;
    cin >> n >> m;
    vector<int> s, c;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        s.push_back(a);
        c.push_back(b);
    }

    int ten=10;
    rep2(i, 1, n){
        ten *= 10;
    }
    rep2(i, ten/10-1, ten){
        if(n!=1&&i==ten/10-1){
            continue;
        }
        bool flag = true;
        rep(j, m){
            int x;
            switch(s[j]+3-n){
                case 3:
                x = i % 10;
                break;
                case 2:
                x = (i/10) % 10;
                break;
                case 1:
                x = i/100;
            }
            if(x!=c[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0; 
}
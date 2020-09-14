#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, x, minim=INT32_MAX;
    cin >> n >> x;
    vector<int> dis;
    rep(i, n){
        int d;
        cin >> d;
        minim = min(minim, abs(d - x));
        dis.push_back(abs(d-x));
    }
    bool flag = true;
    int res = minim;
    while(flag){
        flag = false;
        rep(i, n){
            if(dis[i]%res!=0){
                flag = true;
                res--;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
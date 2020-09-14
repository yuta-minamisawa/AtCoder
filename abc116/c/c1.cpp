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
    vector<int> h;
    rep(i, n){
        int x;
        cin >> x;
        h.push_back(x);
    }
    int cnt=0;
    bool flag=true;
    while(flag){
        flag=false;
        int ind=0, minim=101;
        rep(i, n){
            if(h[i]!=0){
                minim = min(minim, h[i]);
                flag = true;
            }else{
                if(i-ind>0){
                  rep2(j, ind, i) { h[j] -= minim; }
                  cnt+=minim;
                }
                ind = i+1;
                minim = 101;
            }
        }
        if(n-ind>0){
          rep2(i, ind, n) { h[i] -= minim; }
          cnt+=minim;
        }
    }
    cout << cnt << endl;
    return 0;
}
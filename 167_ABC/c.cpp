#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

#define MOD 1000000007

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c;
    vector<vector<int>> a;
    rep(i, n){
        int cost;
        cin >> cost;
        c.push_back(cost);
        vector<int> tmp;
        rep(j, m){
            int A;
            cin >> A;
            tmp.push_back(A);
        }
        a.push_back(tmp);
    }
    int check = 1 << n;
    int minim = INT32_MAX;

    rep(i, check){
        vector<int> und(m, 0);
        int cost=0;
        rep(j, n){
            if(i&(1<<j)){
                cost += c[j];
                rep(k, m){
                    und[k] += a[j][k];
                }
            }
        }
        bool flag=true;
        rep(j, m){
            if(und[j]<x){
                flag = false;
                break;
            }
        }
        if(flag){
            minim = min(cost, minim);
        }
    }

    if(minim!=INT32_MAX)cout << minim << endl;
    else cout << -1 << endl;
    return 0;
}
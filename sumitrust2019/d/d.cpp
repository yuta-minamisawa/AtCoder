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
    string s;
    cin >> s;
    vector<int> tmp(1, -1);
    vector<vector<int>> num(10, tmp);
    int slen = s.size();
    rep(i, slen){
        int x = s[i] - '0';
        num[x].push_back(i);
    }
    int cnt=0, fir, sec;
    rep(i, 10){
        if(num[i].back()==-1){
            continue;
        }else{
            fir = num[i][1];
        }
        rep(j, 10){
            if(num[j].back() <= fir){
                continue;
            }else{
                auto it = upper_bound(num[j].begin(), num[j].end(), fir);
                sec = *it;
            }
            rep(k, 10){
                if(num[k].back() > sec){
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
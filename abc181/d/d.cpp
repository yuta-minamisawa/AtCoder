#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    string s, res = "No";
    cin >> s;
    int slen = s.size();
    vector<int> num(10, 0), req(10, 0);
    rep(i, slen){
        int x = s[i] - '0';
        num[x]++;
    }
    vector<int> tmp(10);
    vector<vector<int>> eight(3, tmp);
    int ten = 1;
    rep(i, 3){
        rep(j, 10){
            eight[i][j] = (ten * j) % 8;
        }
        ten *= 10;
    }
    rep2(i, 111, 1000){
        int now = i;
        int dig=0, check=0;
        while(now>0){
            req[now%10]++;
            check += eight[dig][now%10];
            now/=10;
            dig++;
        }   
        if(check%8){
            rep(i, 10){
                req[i] = 0;
            }
            continue;
        }
        bool flag = true;
        rep(i, 10){
            if(num[i] < req[i]){
                flag = false;
            }
            req[i] = 0;
        }
        if(flag){
            res = "Yes";
            break;
        }
    }
    if(slen < 3){
        if(slen==1){
            int x = s[0] - '0';
            if(x%8==0){
                res = "Yes";
            }
        }else{
            int a, b;
            a = s[1] - '0';
            b = s[0] - '0';
            if((a*10+b)%8==0 || (b*10+a)%8==0){
                res = "Yes";
            }
        }
    }
    cout << res << endl;
    return 0; 
}
#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int a[4], sum=0;
    rep(i, 4){
        int x;
        cin >> x;
        a[i] = x;
        sum += x;
    }

    string res = "No";

    rep(i, 16){
        int check = i;
        int tmp=0, cnt=0;
        while(check>0){
            if(check%2){
                tmp += a[cnt];
            }
            cnt++;
            check /= 2;
        }

        if(tmp*2 == sum){
            res = "Yes";
        }
    }

    cout << res << endl;
    return 0; 
}
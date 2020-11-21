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
    if(n==1&&m==0){
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    if(m<0||n-m-2<0){
        cout << -1 << endl;
    }else{
        int cnt=0;
        rep(i, n-m-2){
            cout << 1+cnt*2 << " " << (cnt+1)*2 << endl;
            cnt++;
        }
        cout << 1+cnt*2 << " " << 2 * n << endl;
        cnt++;
        rep(i, m+1){
            cout << cnt*2 << " " << cnt*2+1 << endl;
            cnt++;
        }
    }
    return 0; 
}
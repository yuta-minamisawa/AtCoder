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
    string c;
    cin >> c;
    int l=-1, r=n, cnt=0;
    while(r-l>1){
        int i;
        for(i=l+1;i<r;i++){
            if(c[i]=='W'){
                l = i;
                break;
            }
        }
        if(i==r){
            break;
        }
        for(i=r-1;i>l;i--){
            if(c[i]=='R'){
                r = i;
                break;
            }
        }
        if(i==l){
            break;
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
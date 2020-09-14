#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a;
    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int l=0, r=a[n-1];
    while(r-l>1){
        int x = (l + r) / 2;
        int tmpk = k, i;
        bool flag=true;
        for(i=n-1;i>=0;i--){
            tmpk -= (a[i] - 1) / x;
            if(tmpk<0){
                flag=false;
                break;
            }
        }
        if(flag){
            r = x;
        }else{
            l = x;
        }
    }
    cout << r << endl;
    return 0;
}
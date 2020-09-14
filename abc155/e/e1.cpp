#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    string n;
    cin >> n;
    int len = n.size();
    cout << len << endl;
    ll ans=0;
    vector<int> bill(len+1, 0);
    // cout << '5' - 1 << endl;
    for(int i=len-1;i>=0;i--){
        if(n[i] - bill[len-1-i] < '6'){
            // ans += n[i] - '0';
            bill[len-1-i] -= n[i] - '0';
        }else{
            // ans += 11 - (n[i] - '0');
            bill[len-i] -= 1;
            bill[len-1-i] += 10 - (n[i] - '0');
        }
    }
    rep(i, len){
        // if(abs(bill[i])>=10){
        //     cout << "over" << endl; 
        //     if(bill[i]>0){
        //         bill[i] -= 10;
        //         bill[i+1] += 1;
        //     }else{
        //         bill[i] += 10;
        //         bill[i + 1] -= 1;
        //     }
        // }
        ans += abs(bill[i]);
        cout << bill[i] << " ";
    }
    // cout << endl;
    ans += abs(bill[len]);
    cout << bill[len] << endl;
    cout << ans << endl;
    return 0;
}
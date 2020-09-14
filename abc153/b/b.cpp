#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int h, n;
    cin >> h >> n;
    int sum=0;
    rep(i, n){
        int x;
        cin >> x;
        sum += x;
    }
    if(sum>=h){
        cout << "Yes";
    }else{
        cout << "No";
    }
    cout << endl;
    return 0;
}
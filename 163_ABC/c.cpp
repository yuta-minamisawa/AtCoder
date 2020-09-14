#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n;
    cin >> n;
    vector<int> a, buka;
    rep(i, n){
        buka.push_back(0);
    }
    rep(i, n-1){
        int sen;
        cin >> sen;
        // a.push_back(sen);
        buka[sen-1]++;
    }
    rep(i, n){
        cout << buka[i] << endl;
    }
    return 0;
}
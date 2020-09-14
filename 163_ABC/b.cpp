#include <bits/stdc++.h>
using namespace std;

#define rep3(i, s, n ,a) for (int i = (s); i < (int)(n); i+=a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

int main(){
    int n, m;
    cin >> n >> m;
    //vector<int> a;
    int sum = 0;
    rep(i, m){
        int day;
        cin >> day;
        //a.push_back(day);
        sum += day;
    }
    if(n>=sum){
        cout << n - sum << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
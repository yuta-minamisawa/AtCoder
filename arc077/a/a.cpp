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
    vector<int> a;
    deque<int> b;
    rep(i, n){
        int x;
        cin >> x;
        a.push_back(x);
        if(n%2==i%2){
            b.push_back(x);
        }else{
            b.push_front(x);
        }
    }    

    rep(i, n){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    queue<int> a;
    rep(i, n){
        int x;
        cin >> x;
        rep(j, x){
            a.push(i+1);
        }
    }
    rep(i, h/2){
        rep(j, w){
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
        stack<int> tmp;
        rep(j, w){
            tmp.push(a.front());
            a.pop();
        }
        rep(j, w){
            cout << tmp.top() << " ";
            tmp.pop();
        }
        cout << endl;
    }
    if(!a.empty()){
        rep(i, w){
            cout << a.front() << " ";
            a.pop();
        }
    }
    cout << endl;
    return 0;
}
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
    vector<int> a(n);
    for(auto& p : a) cin >> p;
    sort(a.begin(), a.end());
    deque<int> dq;
    vector<P> p;
    for(auto x : a){
        dq.push_back(x);
    }
    rep(i, n-2){
        int f, b;
        f = dq.front();
        b = dq.back();
        dq.pop_front();
        dq.pop_back();
        int check;
        bool frontflag = true;
        if(abs(dq.front()) > abs(dq.back())){
            check = dq.front();
            frontflag = false;
        }else{
            check = dq.back();
        }

        int insnum;
        if(check>0){
            insnum = f - b;
            p.push_back(make_pair(f, b));
            dq.push_front(insnum);
        }else{
            insnum = b - f;
            p.push_back(make_pair(b, f));
            dq.push_back(insnum);
        }

    }

    cout << dq.back() - dq.front() << endl;
    for(auto [a, b] : p){
        cout << a << " " << b << endl;
    }
    cout << dq.back() << " " << dq.front() << endl;
    return 0;
}
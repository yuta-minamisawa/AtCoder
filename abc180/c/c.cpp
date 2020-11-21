#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    ll n;
    cin >> n;
    stack<ll> st;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0&&i*i!=n){
            cout << i << endl;
            st.push(n/i);
        }else{
            if(i*i==n){
                cout << i << endl;
            }
        }
    }
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0; 
}
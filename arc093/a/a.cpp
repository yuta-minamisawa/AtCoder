#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() { 
    int n, sum=0;
    cin >> n;
    vector<int> a;
    vector<int> dis(n+1, 0);
    a.push_back(0);
    rep2(i, 1, n+1){
        int x;
        cin >> x;
        a.push_back(x);
        dis[i-1] = abs(a[i] - a[i-1]);
        sum += dis[i-1];
    }
    a.push_back(0);
    dis[n] = abs(a[n]);
    sum += dis[n];
    rep(i, n){
        cout << sum - dis[i] - dis[i+1] + abs(a[i+2] - a[i]) << endl;
    }
    return 0; 
}
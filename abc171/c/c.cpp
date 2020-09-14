#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
    ll n;
    cin >> n;
    vector<ll> total(1, 0);
    ll times=26, sum=26, len=1;
    while(n>sum){
      total.push_back(sum);
      times *= 26;
      sum += times;
      len++;
    }
    vector<char> word;
    n -= total[len - 1] + 1;
    rep(i, len){
        ll x = n % 26;
        char w = (char)((int)'a' + x);
        word.push_back(w);
        n /= 26;
    }
    rep(i, len){
        cout << word[len - i - 1];
    }
    cout << endl;
    // rep(i, 11){
    //     cout << len << " : " << times << endl;
    //     sum += times;
    //     times *= 26;
    //     len++;
    // }
    return 0;
}
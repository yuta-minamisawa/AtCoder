#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> p;
  rep(i, n) {
    int num;
    cin >> num;
    p.push_back(num);
  }
  sort(p.begin(), p.end());
  int sum = 0;
  rep(i, k) { sum += p[i]; }
  cout << sum << endl;
  return 0;
}
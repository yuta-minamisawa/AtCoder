#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a;
  rep(i, n) {
    int x;
    cin >> x;
    a.push_back(x);
  }

  priority_queue<P> pq;
  pq.push(make_pair(1, a[0]));
  rep2(i, 1, n) {
    priority_queue<P> tmp;
    while (!pq.empty()) {
      P p = pq.top();
      if (abs(p.second - a[i]) <= k) {
        pq.push(make_pair(p.first + 1, a[i]));
        break;
      } else {
        tmp.push(p);
        pq.pop();
      }
    }
    if (pq.empty()) {
      pq.push(make_pair(1, a[i]));
    }
    while (!tmp.empty()) {
      pq.push(tmp.top());
      tmp.pop();
    }
  }
  cout << pq.top().first << endl;
  return 0;
}
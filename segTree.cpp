#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int n, q;
vector<int> a;

void update(int i, int x);
int query(int x, int y, int k, int l, int r);

int main() {
  cin >> n >> q;
  rep(i, 30) {
    if ((n - 1) < 1 << i) {
      n = 1 << i;
      break;
    }
  }

  rep(i, 2 * n - 1) { a.push_back(INT32_MAX); }

  rep(i, q) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com) {
      cout << query(x, y + 1, 0, 0, n) << endl;
    } else {
      update(x, y);
    }
  }
  return 0;
}

void update(int i, int x) {
  i += n - 1;
  a[i] = x;
  while (i > 0) {
    i = (i - 1) / 2;
    a[i] = min(a[i * 2 + 1], a[i * 2 + 2]);
  }
}

int query(int x, int y, int k, int l, int r) {
  if (r <= x || y <= l) return INT32_MAX;
  if (x <= l && r <= y)
    return a[k];
  else {
    int vl = query(x, y, k * 2 + 1, l, (l + r) / 2);
    int vr = query(x, y, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
}
#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

void update(int i, int x);
int query(int x, int y, int k, int l, int r);

int n=3e5+1, k;
vector<int> a;

int main(){

    int tmpn;
    cin >> tmpn >> k;

    rep(i, 30) {
        if ((n - 1) < 1 << i) {
            n = 1 << i;
            break;
        }
    }

    rep(i, 2 * n - 1) { a.push_back(0); }

    rep(i, tmpn) {
        int x;
        cin >> x;
        update(x, query(max(0, x-k), min(n, x+k+1), 0, 0, n)+1);
    }

    cout << a[0] << endl;

    return 0;
}

void update(int i, int x) {
  i += n - 1;
  a[i] = x;
  while (i > 0) {
    i = (i - 1) / 2;
    a[i] = max(a[i * 2 + 1], a[i * 2 + 2]);
  }
}

int query(int x, int y, int k, int l, int r) {
  if (r <= x || y <= l) return 0;
  if (x <= l && r <= y)
    return a[k];
  else {
    int vl = query(x, y, k * 2 + 1, l, (l + r) / 2);
    int vr = query(x, y, k * 2 + 2, (l + r) / 2, r);
    return max(vl, vr);
  }
}
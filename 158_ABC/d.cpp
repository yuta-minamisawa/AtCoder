#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  string s, x;
  cin >> s;
  list<char> ans;
  int slen = s.size();
  rep(i, slen) { ans.push_back(s[i]); }
  int q;
  bool rev = false;
  cin >> q;
  rep(i, q) {
    int t;
    cin >> t;
    if (t == 1) {
      rev = !rev;
    } else {
      int f;
      cin >> f;
      char c;
      cin >> c;
      if (f == 1) {
        if (!rev) {
          ans.push_front(c);
        } else {
          ans.push_back(c);
        }
      } else {
        if (rev) {
          ans.push_front(c);
        } else {
          ans.push_back(c);
        }
      }
    }
  }

  if (!rev) {
    for (list<char>::iterator it = ans.begin(); it != ans.end(); it++) {
      cout << *it;
    }
  } else {
    for (list<char>::iterator it = ans.begin(); it != ans.end(); it++) {
      x.push_back(*it);
    }
    int x_len = x.size();
    for (int i = x_len - 1; i >= 0; i--) {
      cout << x[i];
    }
  }
  cout << endl;
  return 0;
}
#include <bits/stdc++.h>
#define rep3(i, s, n, a) for (int i = (s); i < (int)(n); i += a)
#define rep2(i, s, n) rep3(i, s, n, 1)
#define rep(i, n) rep2(i, 0, n)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

// 0-indexed
template <class T>
struct SegmentTree {
  // a,b,c: T, e:T(unit)
  // abc = (ab)c = a(bc)
  // ae = ea = a
  typedef function<T(T, T)> F;
  int n;
  F f;
  T unit;
  vector<T> dat;
  SegmentTree(){};
  // f = f; unit = t;
  SegmentTree(int newn, F f, T t) : f(f), unit(t) { init(newn); }
  SegmentTree(const vector<T> &v, F f, T t) : f(f), unit(t) {
    int _n = v.size();
    init(v.size());
    for (int i = 0; i < _n; ++i) dat[n + i] = v[i];  // 1-indexでは?
    for (int i = n - 1; i; --i) dat[i] = f(dat[i << 1], dat[(i << 1) | 1]);
  }

  // adjust size and fill unit
  void init(int newn) {
    n = 1;
    while (n < newn) n <<= 1;
    dat.assign(n << 1, unit);
  }

  // "go up" process
  void update(int k, T newdata) {
    dat[k += n] = newdata;
    while (k >>= 1) {
      dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
    }
  }
  // [a,b)
  T query(int a, int b) {
    T vl = unit, vr = unit;
    for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, dat[l++]);
      if (r & 1) vr = f(dat[--r], vr);
    }
    return f(vl, vr);
  }
  // func(unit) == false
  // min left: st <= res && func(seg.query(res,n))
  template <typename C>
  int find_left(int st, C &func, T acc, int k, int l, int r) {
    if (l + 1 == r) {
      acc = f(acc, dat[k]);
      return func(acc) ? l : -1;
    }
    int mid = (l + r) >> 1;
    if (mid <= st) return find_left(st, func, acc, (k << 1) | 1, mid, r);
    if (st <= l && !func(f(acc, dat[k]))) {
      acc = f(acc, dat[k]);
      return -1;
    }
    int nres = find_left(st, func, acc, (k << 1), l, mid);
    if (~nres) return nres;
    return find_left(st, func, acc, (k << 1) | 1, mid, r);
  }
  template <typename C>
  int find_left(int st, C &func) {
    T acc = unit;
    return find_left(st, func, acc, 1, 0, n);
  }

  // max right: res <= st && func(seg.query(0,res))
  template <typename C>
  int find_right(int st, C &func, T acc, int k, int l, int r) {
    if (l + 1 == r) {
      acc = f(dat[k], acc);
      return func(acc) ? r : -1;
    }
    int mid = (l + r) >> 1;
    if (st <= mid) return find_right(st, func, acc, k << 1, l, mid);
    if (r <= st && !func(f(dat[k], acc))) {
      acc = f(dat[k], acc);
      return -1;
    }
    int nres = find_right(st, func, acc, (k << 1) | 1, mid, r);
    if (~nres) return nres;
    return find_right(st, func, acc, k << 1, l, mid);
  }
  template <typename C>
  int find_right(int st, C &func) {
    T acc = unit;
    return find_right(st, func, acc, 1, 0, n);
  }
};

int n, k;
vector<int> a;
SegmentTree<int> seg[26];

int main(){
    cin >> n;
    string s;
    cin >> s;

    auto f = [](bool l, bool r) { return l|r; };
    rep(i, 26) {
        seg[i] = SegmentTree<int>(n, f, 0);
    }

    rep(i, n){
        int ind = s[i] - 'a';
        seg[ind].update(i, 1);
    }

    int q;
    cin >> q;
    rep(i, q){
        int t;
        cin >> t;
        if(t==1){
            int ind;
            char c;
            cin >> ind >> c;
            if(s[--ind]!=c){
                seg[s[ind]-'a'].update(ind, 0);
                seg[c-'a'].update(ind, 1);
                s[ind] = c;
            }
        }else{
            int l, r;
            cin >> l >> r;
            l--;
            int res=0;
            rep(i, 26){
                if(seg[i].query(l, r)){
                    res += seg[i].query(l, r);
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}
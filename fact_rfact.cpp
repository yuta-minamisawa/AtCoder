void factorial(ll n) {
  ll m = MOD;
  fact[0] = 1;
  rep2(i, 1, n + 1) { fact[i] = fact[i - 1] * i % m; }
}

void rfactorial(ll n) {
  ll m = MOD;
  rfact[n] = binary_square(fact[n], MOD - 2);
  rep2(i, 1, n + 1) { rfact[n - i] = rfact[n - i + 1] * (n - i + 1) % m; }
}
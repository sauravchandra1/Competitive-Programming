ll pwr(ll x, ll y, ll mod) {
  ll res = 1; 
  x = x % mod;   
  while (y > 0) {
    if (y & 1LL)
      res = (res * x) % mod;
    y = y >> 1LL;   
    x = (x * x) % mod;
  }
  return res;
}
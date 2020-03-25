ll modMul(ll a, ll b, ll mod) {
	ll res = (a % mod * b % mod) % mod;
	return res;
}
ll add(ll a, ll b) {
	ll res = (a % mod + b % mod) % mod;
	return res;
}

ll mul(ll a, ll b) {
	ll res = (a % mod * b % mod) % mod;
	return res;
}
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define N 60
long long num, s, neg_cnt, rem_sum;
vector<long long> pos, inv(N + 10), fact(N + 10);
void calc_fact() {
	fact[0] = 1;
	for (long long i = 1; i < N; i++)
		fact[i] = (fact[i - 1] % MOD * i % MOD) % MOD;
}
long long inverse(long long x) {
	long long y = MOD - 2;
	long long res = 1;
	while(y > 0) {
		if (y & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}
	return res;
}
void calc_inv() {
	for (long long i = 0; i < N; i++) {
		inv[i] = inverse(fact[i]);
	}
}
long long nCr(long long n, long long r) {
	long long ans = (inv[n - r] % MOD * inv[r] % MOD) % MOD;
	return (fact[n] % MOD * ans % MOD) % MOD;
}
long long calc_pos() {
	long long hcf, ans = 0;
	if ((long long)pos.size() >= 2) {
		for (long long i = 0; i < (long long)pos.size() - 1; i++) {
			for (long long j = i + 1; j < (long long)pos.size(); j++) {
				hcf = __gcd(pos[i], pos[j]);
				ans = (ans % MOD + hcf % MOD) % MOD;
			}
		}
	}
	if (neg_cnt >= 2)
		ans = (ans % MOD * nCr(rem_sum - 1, neg_cnt - 1) % MOD) % MOD;
	return ans;
}
long long calc_neg() {
	long long hcf, ans = 0;
	long long reach = rem_sum - neg_cnt + 1, pair_ans = 0;
	if (neg_cnt >= 3) {
		for (long long i = 1; i <= reach; i++) {
			for (long long j = 1; j <= reach - i + 1; j++) {
				hcf = __gcd(i, j);
				pair_ans = (hcf % MOD * nCr(rem_sum - (i + j) - 1, neg_cnt - 3) % MOD) % MOD;
				pair_ans = (pair_ans % MOD * nCr(neg_cnt, 2) % MOD) % MOD;
				ans = (ans % MOD + pair_ans % MOD) % MOD;
			}
		}
	}
	else if (neg_cnt == 2) {
		for (long long i = 1; i < rem_sum; i++) {
			hcf = __gcd(i, rem_sum - i);
			ans = (ans % MOD + hcf % MOD) % MOD;
		}
	}
	return ans;
}
long long calc_pos_neg() {
	long long hcf, ans = 0;
	long long reach = rem_sum - neg_cnt + 1;
	if ((long long)pos.size() == 0) 
		return 0;
	else if (neg_cnt == 0)
		return 0;
	else {
		for (long long i = 1; i <= reach; i++) {
			hcf = 0;
			for (long long j = 0; j < (long long)pos.size(); j++) {
				hcf = (hcf % MOD + __gcd(pos[j], i) % MOD) % MOD;
			}
			hcf = (hcf % MOD * nCr(rem_sum - i - 1, neg_cnt - 2) % MOD) % MOD;
			hcf = (hcf % MOD * neg_cnt % MOD) % MOD;
			ans = (ans % MOD + hcf % MOD) % MOD;
		}
	}
	return ans;
}
int main() {
	calc_fact();
	calc_inv();
	long long t;
	cin >> t;
	while (t--) {
		pos.clear();
		cin >> num >> s;
		long long x, pos_sum = 0;
		neg_cnt = 0;
		for (long long i = 0; i < num; i++) {
			cin >> x;
			if (x < 0) 
				neg_cnt++;
			else {
				pos_sum += x;
				pos.push_back(x);
			}
		}
		if (pos_sum > s) {
			cout << "0" << endl;
			continue;
		}
		rem_sum = s - pos_sum;
		if (num == 1) {
			cout << "0" << endl;
			continue;
		}
		if (neg_cnt > rem_sum) {
			cout << "0" << endl;
			continue;
		}
		if (neg_cnt == 0 && pos_sum != s) {
			cout << "0" << endl;
			continue;
		}
		if (neg_cnt == 1) {
			pos.push_back(rem_sum);
			long long hcf, ans = 0;
			for (long long i = 0; i < (long long)pos.size() - 1; i++) {
				for (long long j = i + 1; j < (long long)pos.size(); j++) {
					hcf = __gcd(pos[i], pos[j]);
					ans = (ans % MOD + hcf % MOD) % MOD;
				}
			}
			cout << ans << endl;
			continue;
		}
		long long pos_ans = calc_pos();
		long long neg_ans = calc_neg();
		long long pos_neg_ans = calc_pos_neg();
		long long ans = (pos_ans % MOD + neg_ans % MOD + pos_neg_ans % MOD) % MOD;
		cout << ans << endl;
	}
	return 0;
}
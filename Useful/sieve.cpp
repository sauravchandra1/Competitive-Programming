bool prime[LIM + 1];

void sieve() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < LIM; i++) {
		if (prime[i]){
			for (int j = i * i ; j < LIM; j += i){
				prime[j] = false;
			}
		}
	}	
}

def sieve(n):
	prime = [True for i in range(n + 1)]
	p = 2
	while p * p <= n:
		if prime[p] == True:
			for i in range(p * 2, n + 1, p):
				prime[i] = False
		p += 1
	ans = 0
	for i in range(2, n + 1):
		if prime[i] == True:
			ans += i
	return ans

n = 2000000
print(sieve(n))

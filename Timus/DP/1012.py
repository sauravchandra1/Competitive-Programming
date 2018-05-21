N = int(input())
K = int(input())
dp = [0 for y in range(2000)]
dp[0] = 0
dp[1] = K
dp[2] = K * (K - 1)
if (N == 2):
	print(dp[2])
else:
	Sum = dp[2]
	zero = (K - 1) * (K - 1) 
	one = Sum * (K - 1)
	for i in range(3, N + 1):
		dp[i] = zero + one
		Sum = dp[i]
		zero = one
		one = Sum * (K - 1)
	print(dp[N])
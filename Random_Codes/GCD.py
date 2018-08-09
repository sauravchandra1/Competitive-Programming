def gcd(a, b):
    if (b == 0):
        return a
    else:
        return gcd(b, a % b)
def power(x, y, p):
    res = 1 
    x = x % p 
    while (y > 0):
        if ((y & 1) == 1) :
            res = (res * x) % p
        y = y >> 1      
        x = (x * x) % p
    return res
t = 0
A = 0
B = 0
N = 0
diff = 0
AN = 0
BN = 0
MOD = 1000000007
t = int(input())
for i in range(t):
	A, B, N = map(int, input().split())
	diff = abs(A - B)
	if (diff == 0):
		AN = power(A, N, MOD)
		BN = power(B, N, MOD)
		ans = (AN % MOD + BN % MOD) % MOD
	else:
		AN = power(A, N, diff);
		BN = power(B, N, diff);
		A = (AN % diff + BN % diff) % diff;
		B = diff;
		ans = gcd(B, A);
	print(ans)

         

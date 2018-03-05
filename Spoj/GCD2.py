def gcd(a,b):
	if b==0:
		return a
	else:
		return gcd(b,a%b)
t=int(input())
for i in range(t):
	b,a=map(int,input().split())
	if a<b:
		temp=a
		a=b
		b=temp
	ans=gcd(a,b)
	print(ans)
